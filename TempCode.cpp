#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int findParent(vector<int>& parent, int node) {
    if (node != parent[node])
    return parent[node] = findParent(parent, parent[node]);
}