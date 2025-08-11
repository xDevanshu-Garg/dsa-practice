#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adj list
    vector<vector<pair<int, int>>> adj(vertices);
    for(auto& edge: vec) {
        adj[edge[0]].push_back({edge[1], edge[2]});        
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    //Set have {distance, node} (dist is first cuz set is sorted by first value and we'll use that)
    set<pair<int, int>> st;
    st.insert({0, source});

    while(!st.empty()) {
        auto top = *(st.begin());
        int nodeDist = top.first;
        int node = top.second;
        st.erase(st.begin());

        // Skip outdated record
        // if (nodeDist > dist[node]) continue; // We can do this to skip cuz if we erase it'll take logn time too so just skip it 

        //Traverse on neighbours
        for(auto& nei: adj[node]) {

            int neiNode = nei.first;
            int neiDist = nei.second;

            if(nodeDist + neiDist < dist[neiNode]) {
                //Update the new distance 
                dist[neiNode] = nodeDist + neiDist;

                //Push new record into the set
                st.insert({dist[neiNode], neiNode});

                //Now we have to delete our old record because we've lesser value
                //erasing will cose logn time but saves memory
                auto record = st.find({nodeDist, node});
                if(record != st.end()) {
                    st.erase(record);
                }
            }
        }
    }
    return dist;
}

//In short: If you have memory concerns then you will use the erase method and if you want to make your code faster you will skip the outdated record 