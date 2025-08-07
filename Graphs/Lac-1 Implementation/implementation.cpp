
//First example (Undir Graph)
/*
n = 4
m = 5

connections:
2 3, 2 5, 2 4, 3 4, 4 5
dia: 
2--------3
| \    /
|   \ /
5----4

adj list: 
2 -> 3 4 5
3 -> 2 4
4 -> 2 3 5
5 -> 2 4

Second example (Dir graph)
same input!!

adj list: 
2 -> 3 4 5
3 -> 4
4 -> 5
5 -> None
*/   

//TC: For addEdge is O(1), inside main we're inserting m edges so m edges in O(1) is O(m) and for printEdges O(V + E) (since we visit each vertex and each stored edge once).
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class graph{
    unordered_map<int, vector<int> > adjList;
public:
    void addEdge(int u, int v, bool dir){
        // 0 -> Undirected Graph
        // 1 -> Directed Graph

        adjList[u].push_back(v);

        // For undir graph v is also connected to u
        if(dir == 0)
            adjList[v].push_back(u);
    }

    void printAdjList() {
        for(auto i: adjList){
            cout << i.first << "-> ";
            for(auto j: i.second){
                cout << j << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    graph g;

    // Input: n = no. of nodes, m = no. of edges, u,v = relation of edges
    int n, m, u, v;
    cout << "Enter no. of nodes: ";
    cin >> n;

    cout << "Enter no. of edges: ";
    cin >> m;

    // Loop as many times as there are edges
    for(int i = 0; i < m; i++){
        cout << "Enter connected edges: ";
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printAdjList();

    graph g2;
    for(int i = 0; i < m; i++){
        cout << "Enter connected edges: ";
        cin >> u >> v;
        g2.addEdge(u, v, 1);
    }
    g2.printAdjList();

    return 0;
}