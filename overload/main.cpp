#include <iostream>


using namespace std;

class stack {

public:
    struct node {
        char value_a{};
        node *next = nullptr;
    };
public:
    typedef node *position;
    position firstNode;
public:
    stack() {
        firstNode = new node;
        firstNode->next = nullptr;
        this->push('#');
    }

    char front() {
        return firstNode->value_a;
    }

    void push(char value) {
        auto pom = new node;
        pom->value_a = value;
        pom->next = firstNode;
        firstNode = pom;
    }

    void pop() {
        position tmp = firstNode;
        position x = firstNode->next;
        firstNode = x;
        delete tmp;


    }

    char show() {
        return firstNode->value_a;
    };


};

class stack_1 {

public:
    struct node {
        double value_a{};
        node *next = nullptr;
    };
public:
    typedef node *position;
    position firstNode;
public:
    stack_1() {
        firstNode = new node;
        firstNode->next = nullptr;
    }

    void push(double value) {
        auto pom = new node;
        pom->value_a = value;
        pom->next = firstNode;
        firstNode = pom;

    }

    double pop() {
        double g = firstNode->value_a;
        position tmp = firstNode;
        position x = firstNode->next;
        firstNode = x;
        delete (tmp);
        return g;
    }


};

class Queue {
public:
    struct node {
        string value;
        node *next{};
    };
    typedef node *position;
    node *front;
    node *back;
public:

    Queue() {
        front = nullptr;
        back = nullptr;
    }

    void insert(string v) {
        auto tmp = new node;
        tmp->value = std::move(v);
        tmp->next = nullptr;
        if (front == nullptr) {
            front = back = tmp;
            tmp->next = nullptr;
        } else {
            back->next = tmp;
            back = tmp;
            back->next = nullptr;
        }
    }

    string pop() {
        position pom = front;
        string g = front->value;
        front = front->next;
        delete pom;
        return g;
    }

};

int setPrior(char c) {
    switch (c) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '/':
            return 2;
        case '*':
            return 2;
        case '(':
            return 0;
        case '[':
            return 0;
        case '{':
            return 0;
        case ')':
            return 0;
        case ']':
            return 0;
        case '}':
            return 0;
        default:
            return 0;


    }
}

bool is_number(string s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string empty() {
    return "";
}

int main() {
    stack stackI = stack();
    stack_1 stack2 = stack_1();
    Queue queue;

    string candidate = empty(), outp = empty(), tmp1 = empty();
    string tmp = empty();

    bool bracket = false, error = false;

    long a = 0, i = 0, in = 0, digit = 0;

    long m = 0, m1 = 0, n = 0, n1 = 0, s = 0, s1 = 0;

    string o;

    std::ios_base::sync_with_stdio(false);

    cin >> a;

    for (i = 0; i < a; i++) {
        std::ios_base::sync_with_stdio(false);

        cin >> candidate;

        for (char c:candidate) {
            if (!error) {
                if (isdigit(c)) {
                    bracket = false;
                    tmp += c;
                    digit++;
                } else {
                    switch (c) {
                        case '+':
                            if (!tmp.empty())
                                queue.insert(tmp);
                            while (setPrior((stackI.front())) >= 1) {
                                tmp1 = stackI.show();
                                stackI.pop();
                                queue.insert(tmp1);
                            }
                            tmp = empty();
                            stackI.push(c);
                            bracket = false;
                            break;
                        case '-':
                            if (!tmp.empty())
                                queue.insert(tmp);
                            if (in == 0 || bracket) {
                                tmp += '-';
                                break;
                            }
                            while (setPrior((stackI.front())) >= 1) {
                                tmp1 = stackI.show();
                                stackI.pop();
                                queue.insert(tmp1);
                            }
                            stackI.push(c);
                            tmp = empty();
                            bracket = false;
                            break;

                        case '*':
                            if (!tmp.empty())
                                queue.insert(tmp);
                            while (setPrior((stackI.front())) >= 2) {
                                tmp1 = stackI.show();
                                stackI.pop();
                                queue.insert(tmp1);
                            }
                            stackI.push(c);
                            tmp = empty();
                            bracket = false;
                            break;

                        case '/':
                            if (!tmp.empty())
                                queue.insert(tmp);
                            while (setPrior((stackI.front())) >= 2) {
                                tmp1 = stackI.show();
                                stackI.pop();
                                queue.insert(tmp1);
                            }
                            stackI.push(c);
                            tmp = empty();
                            bracket = false;
                            break;

                        case '(':
                            n++;
                            if (!tmp.empty())
                                queue.insert(tmp);
                            tmp = empty();
                            bracket = true;
                            stackI.push(c);
                            break;
                        case '[':
                            s++;
                            if (!tmp.empty())
                                queue.insert(tmp);
                            tmp = empty();
                            bracket = true;
                            stackI.push(c);

                            break;
                        case '{':
                            m++;
                            if (!tmp.empty())
                                queue.insert(tmp);
                            tmp = empty();
                            bracket = true;
                            stackI.push(c);

                            break;
                        case ')':
                            n1++;
                            if (!tmp.empty())
                                queue.insert(tmp);
                            tmp = empty();
                            tmp1 = stackI.show();
                            stackI.pop();

                            while (tmp1.at(0) != '(') {
                                if (!error) {
                                    switch (tmp1.at(0)) {
                                        case '[':
                                            error = true;
                                            break;
                                        case '{':
                                            error = true;
                                            break;
                                        case '}':
                                            error = true;
                                            break;
                                        case ']':
                                            error = true;
                                            break;
                                        case ')':
                                            error = true;
                                            break;
                                        case '#':
                                            error = true;
                                            break;
                                        default:
                                            queue.insert(tmp1);
                                            tmp1 = stackI.show();
                                            stackI.pop();
                                            break;
                                    }
                                } else {
                                    break;
                                }
                            }
                            bracket = false;
                            break;
                        case ']':
                            s1++;
                            if (!tmp.empty())
                                queue.insert(tmp);
                            tmp = empty();
                            tmp1 = stackI.show();
                            stackI.pop();
                            while (tmp1.at(0) != '[') {
                                if (!error) {
                                    switch (tmp1.at(0)) {
                                        case '[':

                                            error = true;
                                            break;
                                        case '{':

                                            error = true;
                                            break;
                                        case '}':

                                            error = true;
                                            break;
                                        case ']':

                                            error = true;
                                            break;
                                        case ')':

                                            error = true;
                                            break;
                                        case '(':

                                            error = true;
                                            break;
                                        case '#':

                                            error = true;
                                            break;
                                        default:
                                            queue.insert(tmp1);
                                            tmp1 = stackI.show();
                                            stackI.pop();
                                            break;
                                    }
                                } else {
                                    break;
                                }
                            }
                            bracket = false;
                            break;

                        case '}': {
                            m1++;
                            if (!tmp.empty())
                                queue.insert(tmp);
                            tmp = empty();
                            tmp1 = stackI.show();
                            stackI.pop();
                            while (tmp1.at(0) != '{') {
                                if (!error) {
                                    switch (tmp1.at(0)) {
                                        case '[':

                                            error = true;
                                            break;
                                        case '{':

                                            error = true;
                                            break;
                                        case '}':

                                            error = true;
                                            break;
                                        case ']':

                                            error = true;
                                            break;
                                        case ')':

                                            error = true;
                                            break;
                                        case '#':

                                            error = true;
                                            break;
                                        default:
                                            queue.insert(tmp1);
                                            tmp1 = stackI.show();
                                            stackI.pop();
                                            break;
                                    }
                                } else {
                                    break;
                                }
                            }
                            bracket = false;
                            break;
                        }
                        default:
                            break;
                    }
                }
                in++;
            } else {
                error = true;
                break;
            }
        }
        if (!tmp.empty()) {
            queue.insert(tmp);
        }
        if (!error) {
            while (true) {
                o = stackI.show();
                stackI.pop();
                if (o != "#") {
                    queue.insert(o);
                } else {
                    stackI.push('#');
                    queue.insert("#");
                    break;
                }
            }
        }

        in = 0;
        string con;
        char c;
        bool digitError = false;
        double p = 0, b = 0;
        if (!error) {
            while (con != "#") {
                if (digit == 0) {
                    error = true;
                    digitError = true;
                    break;
                }
                con = queue.pop();
                if (is_number(con)) {
                    stack2.push(stoi(con));
                } else {
                    if (con.size() > 1) {
                        con.erase(0, 1);
                        stack2.push(-1 * stoi(con));
                    } else {
                        c = con.at(0);
                        switch (c) {
                            case '+':
                                if (digit < 2) {
                                    digit = 0;
                                    break;
                                }
                                p = stack2.pop();
                                b = stack2.pop();
                                stack2.push(p + b);
                                break;
                            case '-':
                                if (digit < 2) {
                                    digit = 0;
                                    break;
                                }
                                p = stack2.pop();
                                b = stack2.pop();
                                stack2.push(b - p);
                                break;
                            case '*':
                                if (digit < 2) {
                                    digit = 0;
                                    break;
                                }
                                p = stack2.pop();
                                b = stack2.pop();
                                stack2.push(p * b);
                                break;
                            case '/':
                                if (digit < 2) {
                                    digit = 0;
                                    break;
                                }
                                p = stack2.pop();
                                if (p == 0) {
                                    error = true;
                                    break;
                                }
                                b = stack2.pop();
                                stack2.push(b / p);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }
        double k;
        if (n != n1 || m != m1 || s != s1 || error) {
            if (digitError) {
                cout << " ";
            } else {
                cout << "BLAD";
                cout << "\n";
            }
            stack2 = *new stack_1();
            stackI = *new stack();
            //   queue = *new Queue();
            n = n1 = m = m1 = s = s1 = 0;
            error = false;
            con = o = tmp = tmp1 = "";
            bracket = false;
            digit = 0;
        } else {
            std::ios_base::sync_with_stdio(false);
            k = stack2.pop();
            if (digit == 0) {
                cout << " ";
                cout << "\n";
            } else {
                cout << k;
                cout << "\n";
            }
            stack2 = *new stack_1();
            stackI = *new stack();
            //  queue = *new Queue();
            n = n1 = m = m1 = s = s1 = 0;
            error = false;
            con = o = tmp = tmp1 = "";
            bracket = false;
            digit = 0;
        }
    }
    std::ios_base::sync_with_stdio(false);


    return 0;
}