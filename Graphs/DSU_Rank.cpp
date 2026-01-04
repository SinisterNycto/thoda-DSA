// DSU by union by rank + path compression
// we use DSU to tell whether two nodes belong to same set
// Each set is represented as a tree

// T.C: O(4 alpha) as good as O(1)

// DSU is used to keep track of connected components
// used in dynamic graphs(edges are changing)
// DSU supports: 1.) find: which set an ele belongs to
// 2.) Union: merge two sets

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
        vector<int> rank, parent;
    public:
        DisjointSet(int n){ // n is size, creates n + 1 elements
            // 1 based indexed graph
            rank.resize(n + 1, 0);
            parent.resize(n + 1);

            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
        }

        // Find ultimate parent(Path Compression)
        //

        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }

            return parent[node] = findUPar(parent[node]); // path compression line
        }

        void unionByRank(int u, int v){
            int ulp_u = findUPar(u); // ultimate parent of u
            int ulp_v = findUPar(v); // ultimate parent of v
            // If already same → do nothing
            if(ulp_u == ulp_v) return;

            // Attach smaller-rank tree under larger-rank tree
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }

            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }

            // if ranks are equal, attach one under the other and
            // inc. rank of the above tree by 1
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // 3 and 7 same or not
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout << "Same\n";
    }
    else cout << "Not Same\n";

    ds.unionByRank(3, 7);

    if(ds.findUPar(3) == ds.findUPar(7)){
        cout << "Same\n";
    }

    else cout << "Not Same\n";

    return 0;
}