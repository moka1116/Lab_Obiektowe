#include <iostream>
#include <list>


using namespace std;



class Node {

public:
    int value{};
    Node *LSon = nullptr;
    Node *RSon = nullptr;


};

class Queue {
public:
    struct node {
        Node *value{};
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

    void insert(Node *v) {
        auto tmp = new node;
        tmp->value = v;
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

    void pop() {
        position pom = front;
        Node *g = front->value;
        front = front->next;
        delete pom;

    }

    Node *first() {
        return this->front->value;
    }

};

class Tree {
public:
    Node *root;

    Tree() {
        root = nullptr;
    }

    void insert(int v) {
        auto tmp = new Node;
        tmp->value = v;
        root = tmp;
    }

    Node *insert(int v, Node *n, bool f) {
        auto tmp = new Node;
        tmp->value = v;

        if (f) {
            n->LSon = tmp;
            return n->LSon;
        } else {
            n->RSon = tmp;
            return n->RSon;
        }
    }


};

int counter;

void PST(Node *node, list<int> &tmp, int length) {

    list<int> l, p;

    if (node->LSon != nullptr) {
        PST(node->LSon, l, length);
    }
    if (node->RSon != nullptr) {
        PST(node->RSon, p, length);
    }
    if (node->value == length) {
        counter++;
    } else {
        if (node->value < length) {
            tmp.push_back(node->value);
        }
    }

    for (auto chk:l) {
        for (auto chk_1:p) {
            if (chk + chk_1 == length) {
                counter++;
            }
        }
    }

    for (auto chk:l) {
        if (chk + node->value == length) {
            counter++;
        } else {
            if (chk + node->value < length) {
                tmp.push_back(chk + node->value);
            }
        }
    }

    for (auto chk:p) {
        if (chk + node->value == length) {
            counter++;
        } else {
            if (chk + node->value < length) {
                tmp.push_back(chk + node->value);
            }
        }
    }


}

int main() {

    int quantityOfTests, length, quantityOfBranches, element;
    std::ios_base::sync_with_stdio(false);
    cin >> quantityOfTests;
    std::ios_base::sync_with_stdio(false);
    list<int> lista;

    for (int i = 0; i < quantityOfTests; i++) {
        counter = 0;
        cin >> quantityOfBranches;
        cin >> length;
        Tree drzewo = Tree();
        Queue kolejka = Queue();
        drzewo.insert(0);
        kolejka.insert(drzewo.root);


        for (int j = 0; j < quantityOfBranches; j++) {
            cin >> element;
            if (kolejka.first()->LSon == nullptr) {
                kolejka.insert(drzewo.insert(element, kolejka.first(), true));
            } else {
                kolejka.insert(drzewo.insert(element, kolejka.first(), false));
                kolejka.pop();
            }


        }

        PST(drzewo.root, lista, length);
        cout << '\n' << counter;
        lista.clear();

    }


    return 0;
}