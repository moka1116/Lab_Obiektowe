#include <iostream>


using namespace std;

struct moves {
    int positionX;
    int positionY;
};

struct disc {
    int c{};
    string s;
};

class list {
    typedef disc value;

public:
    struct node {
        value value_a;
        node *next{};

    };


public:

    typedef node *position;
    position firstNode, lastNode;

public:
    list() {
        firstNode = nullptr;
        lastNode = nullptr;

    }

    bool empty() {
        return firstNode == nullptr;
    }

    void push_back(disc v) {
        auto tmp = new node;
        tmp->value_a = v;
        if (firstNode == NULL) {
            auto pom = new node;
            pom->value_a = v;
            pom->next = firstNode;
            firstNode = pom;
            lastNode = firstNode;
        } else {
            position tmp_2 = lastNode;
            tmp->next = firstNode;
            tmp_2->next = tmp;
            lastNode = tmp;

        }
    }

    void pop_front() {
        if (firstNode != firstNode->next) {
            position pom = firstNode;
            firstNode = firstNode->next;
            lastNode->next = firstNode;
            delete pom;
        } else {
            position pom = firstNode;
            firstNode = lastNode = nullptr;
            //  delete pom;
        }
    }

    void erase(position p) {
        if (p == firstNode) {
            pop_front();
        } else {
            if (p == lastNode) {
                position pom, it = firstNode;
                while (it->next != lastNode)
                    it = it->next;
                pom = it;
                delete pom;
                lastNode = it;
            } else {
                if (p != NULL) {
                    position pom = p->next;
                    p->next = pom->next;
                    delete pom;
                }
            }


        }


    }


};

class listL {
    typedef list *valueL;

public:
    struct node {
        valueL value_a;
        node *next;

    };
public:
    typedef node *positionL;
    positionL lastNode;
    positionL firstNode;
public:
    listL() {
        firstNode = nullptr;
        lastNode = nullptr;

    }

    bool empty() {
        return firstNode == nullptr;
    }

    void push_back(valueL v) {
        auto tmp = new node;
        tmp->value_a = v;
        if (firstNode == NULL) {
            auto pom = new node;
            pom->value_a = v;
            pom->next = firstNode;
            firstNode = pom;
            lastNode = firstNode;
        } else {
            positionL tmp_2 = lastNode;
            tmp->next = firstNode;
            tmp_2->next = tmp;
            lastNode = tmp;

        }
    }

    void pop_front() {
        if (firstNode != firstNode->next->next) {//todo
            //first node nie poró∑na się z lastem bo to są struktóry możesz napisać comperator, albo
            //zorganizować to w jakiśinny sposób
            //sprawdź czy działa.
            positionL pom = firstNode;
            firstNode = firstNode->next;
            lastNode->next = firstNode;
            delete pom;
        } else {
            positionL pom = firstNode;
            firstNode = lastNode = nullptr;
            //  delete pom;
        }
    }

    void erase(positionL p) {
        if (p == firstNode) {
            pop_front();
        } else {
            if (p == lastNode) {
                positionL pom, it = firstNode;
                while (it->next != lastNode)
                    it = it->next;
                pom = it;
                delete pom;
                lastNode = it;
            } else {
                if (p != NULL) {
                    positionL pom = p->next;
                    p->next = pom->next;
                    delete pom;
                }
            }


        }


    }

    void pop_back() {
        positionL pom, it = firstNode;
        while (it->next != lastNode)
            it = it->next;
        pom = it->next;
        it->next = firstNode;
        lastNode = it;
        delete pom;
    }
};


void move(listL lista, moves move, int globalX) {
    listL::positionL chk = lista.firstNode;
    for (int i = 0; i < globalX; i++) {
        chk = chk->next;
    }
    list::position chk_1 = chk->value_a->firstNode;
    for (int j = 0; j < move.positionY; ++j) {
        chk_1 = chk_1->next;
    }
    chk->value_a->firstNode = chk_1;

}

int constructSerial(listL lista, int qod) {
    int serialNumber = 0;
    listL::positionL chk = lista.firstNode;
    for (int i = 0; i < qod; i++) {
        if (chk->value_a->firstNode != nullptr) {
            serialNumber = serialNumber + chk->value_a->firstNode->value_a.c;
        }
        chk = chk->next;
    }
    return serialNumber;
}

int checkSerial(int serialNumber, int serialNumberCounterArray[], int size) {
    int srl = 0;
    for (int i = 0; i < size; i++) {
        if (serialNumber == serialNumberCounterArray[i]) {
            srl = serialNumber;
            serialNumberCounterArray[i] = 0;
            break;
        }
    }
    return srl;
}

int main() {

    listL lista = listL();
    int quantityOfDiscs = 0, r = 0, quantityOfSigns = 0, serialNumberCounter = 0, globalX = 0, evaluation = 0, pairNumberCounter = 0;
    std::ios_base::sync_with_stdio(false);
    cin >> quantityOfDiscs;
    lista.push_back(new list());
    listL::positionL chk;
    disc tmp;


    for (int i = 0; i < quantityOfDiscs; i++) {

        std::ios_base::sync_with_stdio(false);
        cin >> quantityOfSigns;

        lista.push_back(new list());
        if (i == 0) {
            chk = lista.firstNode;
        }
        for (int j = 0; j < quantityOfSigns; j++) {
            std::ios_base::sync_with_stdio(false);
            cin >> tmp.s;
            cin >> tmp.c;

            chk->value_a->push_back(tmp);
        }
        chk = chk->next;
    }

    lista.pop_back();

    std::ios_base::sync_with_stdio(false);
    cin >> serialNumberCounter;

    int serialNumberCounterArray[serialNumberCounter];
    for (int k = 0; k < serialNumberCounter; ++k) {
        std::ios_base::sync_with_stdio(false);
        cin >> serialNumberCounterArray[k];
    }


    std::ios_base::sync_with_stdio(false);
    cin >> pairNumberCounter;

    struct moves movesArray[pairNumberCounter];
    for (int l = 0; l < pairNumberCounter; ++l) {
        std::ios_base::sync_with_stdio(false);
        cin >> movesArray[l].positionX;
        std::ios_base::sync_with_stdio(false);
        cin >> movesArray[l].positionY;
    }

    listL::positionL chke = lista.firstNode;

    evaluation = checkSerial(constructSerial(lista, quantityOfDiscs), serialNumberCounterArray,
                             serialNumberCounter);

    int snc = serialNumberCounter;
    bool br = false;

    for (;;) {
        if (br) {
            br = false;
            break;
        }
        if (lista.empty())
            break;
        if (evaluation) {


            snc--;

            cout << evaluation << " ";
            chke = lista.firstNode;

            for (int i = 0; i < serialNumberCounter; i++) {
                if (evaluation == serialNumberCounterArray[i]) {
                    serialNumberCounterArray[i] = 0;
                    break;
                }
            }


            for (int i = 0; i < quantityOfDiscs; i++) {
                if (chke->value_a->firstNode != nullptr) {
                    cout << chke->value_a->firstNode->value_a.s;
                }
                chke = chke->next;
            }

            chke = lista.firstNode;
            int q = quantityOfDiscs;
            for (int j = 0; j < q; ++j) {
                chke->value_a->erase(chke->value_a->firstNode);
                if (chke->value_a->empty()) {
                    lista.erase(chke);
                    //
                    quantityOfDiscs--;
                }
                chke = chke->next;
            }

            if (quantityOfDiscs <= 0 || snc == 0) {
                break;
            }

            cout << "\n";

            evaluation = checkSerial(constructSerial(lista, quantityOfDiscs), serialNumberCounterArray,
                                     serialNumberCounter);
        } else {
            while (!evaluation) {
                if (br) {
                    break;
                }
                globalX =
                        (quantityOfDiscs + (globalX + movesArray[r].positionX) % quantityOfDiscs) % quantityOfDiscs;

                move(lista, movesArray[r], globalX);
                r++;
                evaluation = checkSerial(constructSerial(lista, quantityOfDiscs), serialNumberCounterArray,
                                         serialNumberCounter);
                if (pairNumberCounter <= r && evaluation == 0)
                    br = true;
                break;
            }
        }


    }


    return 0;
}
