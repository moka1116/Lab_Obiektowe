#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
vector<int> g;

class Node {
public:
    int value{};
    bool camera{};
    int quantityOfSons{};
    Node *Dad = nullptr;
    Node *Rbrt = nullptr;
    Node *LSon = nullptr;

    void setCamera() {
        this->camera = true;
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

    void insert(int v, Node *n) {
        auto tmp = new Node;
        n->quantityOfSons++;
        tmp->Dad = n;
        tmp->value = v;
        if (n->LSon == nullptr) {
            n->LSon = tmp;
            //Jeśli lewy syn jest NULL-em to wstawiam go na jego miejsce;
        } else {
            Node *pos = n->LSon;
            //Jeśli lewy syn nie jest NULL-em
            while (pos->Rbrt != nullptr) {
                pos = pos->Rbrt;
                //szukam pierwszego prawego brata lewego syna który jest NULL-em i tam go wstawiam
            }
            pos->Rbrt = tmp;

        }
    }


    void preOrderInsertion(Node *root, int key, int value) {
        if (root != nullptr) {
            //Jeśli węzeł nie jest NULL-em to
            if (root->value == key) {
                //Jeśli klucz jest równy wartości węzłą, zrób insert na węźle
                this->insert(value, root);
            } else {
                //Sprawdź czy wartość węzła nie jest równa kluczowi
                //Jeśli nie to
                if (root->LSon != nullptr)
                   // preOrderInsertion(root->LSon, key, value);
                //Wywołaj funkcjęna lewym synu
                if (root->Rbrt != nullptr)
                    preOrderInsertion(root->Rbrt, key, value);
                //Wywołaj funkcję na prawym bracie

            }
        }
    }
};

void preOrder(Node *root, int parametr) {
    //Przechodzę drzewo w kolejności preorder
    if (root != nullptr) {
        if (root->quantityOfSons + 1 >= parametr) {
            //Jeśli ilość synów jest większa lub równa parametr
            if (root->Dad != nullptr && !root->Dad->camera) {
                //Sprawdzam czy ojciec ma kamerę
                //Oraz czy nie jest korzeniem

                root->setCamera();
                g.push_back(root->value);
                //Ustawiam kamere
            }
        } else {
            if (root->Dad != nullptr && !root->Dad->camera) {
                if (root->Dad->Dad != nullptr && !root->Dad->Dad->camera) {
                    if (root->Dad->Dad->Dad != nullptr && !root->Dad->Dad->Dad->camera) {
                        root->setCamera();
                        g.push_back(root->value);
                    }
                }
            }
        }
        if (root->LSon != nullptr)
            preOrder(root->LSon, parametr);
        if (root->Rbrt != nullptr)
            preOrder(root->Rbrt, parametr);
    }
}


int main() {
    Tree drzewo = Tree();
    drzewo.insert(1);
    drzewo.root->setCamera();
    g.push_back(drzewo.root->value);
    int quantityOfCrossing, parameter, dad, son;
    std::ios_base::sync_with_stdio(false);
    cin >> quantityOfCrossing;
    //Liczba skrzyżowań
    std::ios_base::sync_with_stdio(false);
    cin >> parameter;
    //Minimalną ilość dróg które powinny zbiegać się na monitorowanym skrzyżowaniu


    for (int i = 0; i < quantityOfCrossing - 1; i++) {
        std::ios_base::sync_with_stdio(false);
        cin >> dad;
        std::ios_base::sync_with_stdio(false);
        cin >> son;
        drzewo.preOrderInsertion(drzewo.root, dad, son);
    }

    preOrder(drzewo.root, parameter);
    std::sort(g.begin(), g.end());
    for (int &i : g) {
        std::ios_base::sync_with_stdio(false);
        cout << i << " ";
    }

    return 0;
}