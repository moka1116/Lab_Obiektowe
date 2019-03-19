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

void preOrder(Node *root, int parametr) {

    if (root != nullptr) {
        if (root->quantityOfSons + 1 >= parametr) {
            if (root->Dad != nullptr && !root->Dad->camera) {
                root->setCamera();
                g.push_back(root->value);
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


int main() {

    int quantityOfCrossing, parameter, dad, son;
    std::ios_base::sync_with_stdio(false);
    cin >> quantityOfCrossing;
    cin >> parameter;

    Node *s[quantityOfCrossing + 1];
    for (int i = 0; i < quantityOfCrossing + 1; i++) {
        s[i] = new Node;
        s[i]->value = i;
    }

    s[1]->setCamera();
    g.push_back(1);

    for (int i = 0; i < quantityOfCrossing - 1; i++) {
        std::ios_base::sync_with_stdio(false);
        cin >> dad;
        cin >> son;
        if (s[dad]->LSon == nullptr) {
            s[dad]->quantityOfSons++;
            s[dad]->LSon = s[son];
            s[son]->Dad = s[dad];
        } else {
            s[dad]->quantityOfSons++;
            Node *chk = s[dad]->LSon;
            while (chk->Rbrt != nullptr) {
                chk = chk->Rbrt;
            }
            s[chk->value]->Rbrt = s[son];
            s[son]->Dad = s[dad];
        }

    }

    preOrder(s[1], parameter);

    std::sort(g.begin(), g.end());
    for (int &i : g) {
        std::ios_base::sync_with_stdio(false);
        cout << i << " ";
    }

    return 0;
}
