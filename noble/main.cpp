#include <iostream>
#include <vector>


using namespace std;

vector<vector<int> > results;
vector<vector<int> > adjacencyList;

void DFS(int actual, int target, int &length, int *path, bool *ifVisitedArray) {
    path[length] = actual;
    length++;
    ifVisitedArray[actual] = true;

    if (actual != target) {
        for (auto tmp: adjacencyList[actual])
            if (!ifVisitedArray[tmp])
                DFS(tmp, target, length, path, ifVisitedArray);

    } else {
        vector<int> result;
        result.reserve((unsigned long) (length));
        for (int i = 0; i < length; i++) {
            result.push_back(path[i]);
        }
        results.push_back(result);
    }

    length--;
    ifVisitedArray[actual] = false;
}

void DFS(int endPoint, int quantityOfCollectionPoints) {
    int path[quantityOfCollectionPoints], length = 0;
    bool ifVisitedArray[quantityOfCollectionPoints];
    for (int i = 0; i < quantityOfCollectionPoints; i++) {
        ifVisitedArray[i] = false;
    }

    DFS(0, endPoint, length, path, ifVisitedArray);
}


int main() {
    vector<int> a;
    int quantityOfData, quantityOfCollectionPoints, quantityOfPassing, endPointNumber, quantityOfPackages, i, j, x, y, counter;
    std::ios_base::sync_with_stdio(false);
    cin >> quantityOfData;
    for (i = 0; i < quantityOfData; i++) {
        counter = 0;
        std::ios_base::sync_with_stdio(false);
        cin >> quantityOfCollectionPoints;
        cin >> quantityOfPassing;
        cin >> endPointNumber;
        cin >> quantityOfPackages;

        for (int k = 0; k < quantityOfCollectionPoints; ++k) {
            adjacencyList.push_back(a);
        }//wypełnienie listy sąsiedztw pustymi wektorami

        for (j = 0; j < quantityOfPassing; j++) {
            std::ios_base::sync_with_stdio(false);
            cin >> x;
            cin >> y;
            adjacencyList[x].push_back(y);
        }//koniec wczytywanie danych
        vector<int> memory;

        DFS(endPointNumber, quantityOfCollectionPoints);

        for (const auto &p:results) {
            if ((p.size() - 1) == quantityOfPackages) {
                counter++;
            }
            for (auto g:p) {
                cout << g << " ";

            }
            cout << endl;
        }

        cout << counter;

        results.clear();
        adjacencyList.clear();
    }//koniec pętli głównej

    return 0;
}