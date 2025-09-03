#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
    vector<int> parent, size;  // size[i] = size of set whose parent is i

    DSU(int n) { //constructor
        parent.resize(n+1);
        size.resize(n+1, 1);  // initially, every set has size 1
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return; // already in same set

        // attach smaller set under bigger set
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main() {
    DSU dsu(7);

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);
    dsu.unionBySize(5, 6);
    dsu.unionBySize(3, 7);

    // Check connectivity
    if(dsu.findParent(1) == dsu.findParent(7))
        cout << "Same component\n";
    else
        cout << "Different components\n";

        cout << dsu.size[4];

    return 0;
}
