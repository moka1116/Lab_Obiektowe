#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int quantityOfBottles;

class Box {
public:
    double checksum{};
    double *bottles;

    Box() {};

    Box(int size) {
        bottles = new double[size];
    }

};

class ListaBox {
public:
    typedef int pozycja;
    typedef Box wartosc;
    wartosc *tab;
    unsigned int n, roz_tab;

    ListaBox() {
        n = 0;
        roz_tab = 10;
        tab = new wartosc[roz_tab];
    }


    void push_back(wartosc w) {
        if (this->n == this->roz_tab) {
            roz_tab *= 2;
            auto *tab_pom = new wartosc[roz_tab];
            for (unsigned int i = 0; i < n; i++)
                tab_pom[i] = tab[i];
            delete tab;
            tab = tab_pom;
        }
        tab[n] = w;
        n++;
    }

    auto &operator[](int g) {
        return this->tab[g];

    }

};

class ListaList {
public:
    typedef int pozycja;
    typedef ListaBox wartosc;
    wartosc *tab;
    unsigned int n, roz_tab;

    ListaList() {
        n = 0;
        roz_tab = 10;
        tab = new wartosc[roz_tab];
    }


    void push_back(wartosc w) {
        if (this->n == this->roz_tab) {
            roz_tab *= 2;
            auto *tab_pom = new wartosc[roz_tab];
            for (unsigned int i = 0; i < n; i++)
                tab_pom[i] = tab[i];
            delete tab;
            tab = tab_pom;
        }
        tab[n] = w;
        n++;
    }

    auto &operator[](int g) {
        return this->tab[g];

    }

};

bool cmp(Box a, Box b) {
    return a.checksum <= b.checksum;
}

void InsertSort(ListaBox vec) {
    Box pom;
    int n = vec.n;
    int j;
    for (int i = 1; i <= n; i++)
        if (vec[i].checksum < vec[i - 1].checksum) {
            pom = vec[i].checksum;
            for (j = i - 1; (j >= 0) && (vec[j].checksum >= pom.checksum); j--) {
                vec[j + 1] = vec[j];
            }
            vec[j + 1] = pom;
        }
}


void kubel(Box **tab, int quantityOfBoxes, int capacity) {
    ListaBox b;//wektor tymczasowy
    ListaList pom;// wektor na kubełki

    for (int i = 0; i < quantityOfBoxes; i++) {
        pom.push_back(b);// wypełniam wektor pustymi wektorami
    }

    for (int i = 0; i < quantityOfBoxes; i++) {
        int ind = (int) tab[i]->checksum;//wybieram do którego kubła
        pom[ind].push_back(*tab[i]);// pcham w odpowiedni kubek
    }


    for (int i = 0; i < quantityOfBoxes; i++) {
        InsertSort(pom[i]);
    }
    cout << pom[0].tab[2].bottles[0] << " ";
    cout << pom[0].tab[2].bottles[1] << " ";
    cout << pom[0].tab[2].bottles[2] << " ";
    cout << pom[0].tab[2].bottles[3] << " ";
    cout << pom[0].tab[2].bottles[4] << " ";



}

int main() {
    std::ios_base::sync_with_stdio(false);
    double ph;
    int quantityOfBoxes, capacity, index;


    cin >> quantityOfBoxes;
    cin >> quantityOfBottles;
    cin >> capacity;

    Box **boxes = new Box *[quantityOfBoxes];
    for (int i = 0; i < quantityOfBoxes; ++i) {
        boxes[i] = new Box(quantityOfBottles);
    }

    double checksum;
    for (int r = 0; r < quantityOfBoxes; r++) {
        index = 0;
        checksum = 0;
        for (int m = 0; m < quantityOfBottles; m++) {
            cin >> ph;
            boxes[r]->bottles[index] = ph;
            index++;
            checksum += ph;
        }
        boxes[r]->checksum = checksum;

    }


    kubel(boxes, quantityOfBoxes, capacity);
    return 0;
}


