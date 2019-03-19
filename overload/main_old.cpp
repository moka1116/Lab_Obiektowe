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

    void push(char element) {
        auto *tmp = new node;
        if (firstNode == NULL) {
            tmp->value_a = element;
            tmp->next = NULL;
            firstNode = tmp;
        } else {
            tmp->value_a = element;
            tmp->next = firstNode;
            firstNode = tmp;

        }
    }


    char pop() {
        char g = firstNode->value_a;
        position tmp = firstNode;
        position x = firstNode->next;
        firstNode = x;
        return tmp->value_a;
    }

};

class stack_1 {

public:
    struct node {
        double value_a = 0;
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


    void push(double element) {
        auto *tmp = new node;
        if (firstNode == NULL) {
            tmp->value_a = element;
            tmp->next = NULL;
            firstNode = tmp;
        } else {
            tmp->value_a = element;
            tmp->next = firstNode;
            firstNode = tmp;

        }
    }

    double pop() {
        double g = firstNode->value_a;
        position tmp = firstNode;
        firstNode = firstNode->next;
        return tmp->value_a;

    }


};

class priorityQueueChar {
public:
    struct node {
        string value;
        node *next = nullptr;
    };
    typedef node *position;

    node *front = nullptr;
    //node *back;
public:

    priorityQueueChar() {
        front = nullptr;
    }

    void insert(string value) {
        position tmp, q;
        tmp = new node;
        tmp->value = move(value);
        if (front == nullptr) {
            tmp->next = front;
            front = tmp;
            // back = front;
        } else {
            q = front;
            while (q->next) {
                q = q->next;
            }
            tmp->next = q->next;
            q->next = tmp;

        }
    }

    string pop() {
        node *tmp;
        string g = front->value;
        tmp = front;
        front = front->next;
        delete tmp;
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

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string empty() {
    return "";
}

int main() {
    stack stackI = stack(), s12;
    stack_1 stack2 = stack_1(), s13;
    priorityQueueChar queue, p1;
    string candidate = empty(), outp = empty(), tmp1 = empty();
    string tmp = empty();
    bool bracket = false, error = false;
    int a = 0, i = 0, in = 0;
    int m = 0, m1 = 0, n = 0, n1 = 0, s = 0, s1 = 0;
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
                } else {
                    switch (c) {
                        case '+':
                            if (!tmp.empty())
                                queue.insert(tmp);
                            while (setPrior((stackI.front())) >= 1) {
                                tmp1 = stackI.pop();
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
                                tmp1 = stackI.pop();
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
                                tmp1 = stackI.pop();
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
                                tmp1 = stackI.pop();
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
                            tmp1 = stackI.pop();
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
                                            tmp1 = stackI.pop();
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
                            tmp1 = stackI.pop();
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
                                            tmp1 = stackI.pop();
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
                            tmp1 = stackI.pop();
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
                                            tmp1 = stackI.pop();
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
                o = stackI.pop();
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
        double p = 0, b = 0;
        if (!error) {
            while (con != "#") {
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
                                stack2.push(stack2.pop() + stack2.pop());
                                break;
                            case '-':
                                p = stack2.pop();
                                b = stack2.pop();
                                stack2.push(b - p);
                                break;
                            case '*':
                                stack2.push(stack2.pop() * stack2.pop());
                                break;
                            case '/':
                                p = stack2.pop();
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

        if (n != n1 || m != m1 || s != s1 || error) {
            cout << "BLAD";
            stack2 = s13;
            stackI = s12;
            queue = p1;
            n = n1 = m = m1 = s = s1 = 0;
            error = false;
        } else {
            std::ios_base::sync_with_stdio(false);
            cout << stack2.pop();
            con = o = tmp = tmp1 = "";
            bracket = false;
        }
        std::ios_base::sync_with_stdio(false);
        cout << "\n";
    }


    return 0;
}