#include<bits/stdc++.h>
using namespace std;


class Graph{

    public:
    unordered_map<int,vector<int>>adj;
    void addnode(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    bool issafe(int node,int c,vector<int>&color){
        for(auto nbr:adj[node]){
            if(color[nbr]==c)return false;
        }
        return true;
    }


    bool color_graph(int node,int m,int n,vector<int>&color){
        if (node==n )return true;
        for(int c=1;c<=m;c++){
            if(issafe(node,c,color)){
                color[node]=c;
                if(color_graph(node+1,m,n,color)){
                    return true;
                }
                color[node]=0;
            }
        }
        return false;
    }

    bool graph_c(int m, int n){
        vector<int>color(n,0);
        bool ans=color_graph(0,m,n,color);
        return ans;
    }


    int graph_coloring_branch_bound(int n) {
        for (int m = 1; m <= n; m++) { // try from 1 to n colors
            vector<int> color(n, 0);
            if (color_graph(0, m, n, color)) {
                cout << "Minimum colors required: ";
                return m;
            }
        }
        return n; // worst case
    }


};


int main(){
    Graph g;
    int n = 4; 
    g.addnode(0, 1);
    g.addnode(1, 2);
    g.addnode(2, 3);
    g.addnode(3, 0);
    g.addnode(0, 2); 

    // int m = 3; 

    // if (g.graph_c(m, n)) {
    //     cout << "Graph can be colored with " << m << " colors.\n";
    // } 
    // else {
    //     cout << "Graph cannot be colored with " << m << " colors.\n";
    // }

    int min_colors = g.graph_coloring_branch_bound(n);

    cout << min_colors << "\n";


    
    return 0;
}