#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

bool globalChk = false;
vector<vector<int >> review;

bool isCyclicUtil(vector<vector<int> > adj, int v, bool visited[], bool *recStack) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i] && isCyclicUtil(adj, *i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false;
    return false;
}


bool isCyclic(int V, vector<vector<int> > adj) {

    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (isCyclicUtil(adj, i, visited, recStack)) {
            return true;
        }
}

void BFS(int s, int V, vector<vector<int> > adj) {

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;
    vector<int> result;
    visited[s] = true;
    queue.push_back(s);

    int counter = 0;
    while (!queue.empty()) {
        bool ek = false;
        s = queue.front();
        result.push_back(s);
        queue.pop_front();


        for (int &i : adj[s]) {
            if (!visited[i]) {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }

}

int main() {
    vector<vector<int> > adjacencyList;

    int quantityOfGames, quantityOfFields, quantityOfRoads, firstField, x, y;
    vector<int> a;
    std::ios_base::sync_with_stdio(false);
    cin >> quantityOfGames;

    for (int i = 0; i < quantityOfGames; i++) {
        std::ios_base::sync_with_stdio(false);
        cin >> quantityOfFields;
        cin >> quantityOfRoads;
        cin >> firstField;
        for (int k = 0; k < quantityOfFields; ++k) {
            adjacencyList.push_back(a);
        }


        for (int j = 0; j < quantityOfRoads; ++j) {
            std::ios_base::sync_with_stdio(false);
            cin >> x;
            cin >> y;
            adjacencyList[x].push_back(y);
        }


     //   cout << "Is cyclic : " << isCyclic(quantityOfFields, adjacencyList) << "\n";
        BFS(firstField, quantityOfFields, adjacencyList);
        adjacencyList.clear();

        globalChk = false;


    }
    //todo
    //możesz sprawdzać drogę do wierzchołka który ma tylko jedną krawędź


    //### wypisywanie zawartości grafu###
    /*cout<<"\n";
for (int i = 0; i < quantityOfFields; i++) {
         cout << i << ": ";
         for (auto &z:adjacencyList[i]) {
             cout << z << " ";
         }
         cout << "\n";
     }*/



    return 0;
}
