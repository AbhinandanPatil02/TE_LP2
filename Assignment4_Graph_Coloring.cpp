#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, vector<int>> adjlist;

    void addnode(int u, int v) {
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

private:
    bool isSafe(int node, int c, vector<int>& color) {
        for (int nbr : adjlist[node]) {
            if (color[nbr] == c){
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int m, int n, vector<int>& color) {
        if (node == n) return true; 

        for (int c = 1; c <= m; c++) {
            if (isSafe(node, c, color)) {
                color[node] = c;
                if (solve(node + 1, m, n, color)) return true;
                color[node] = 0; // Backtrack
            }
        }

        return false;
    }

public:

    bool isColorable(int m, int n) {
        vector<int> color(n, 0);
        return solve(0, m, n, color);
    }
};




int main() {
    graph g;
    int n = 5; 



    // g.addnode(0, 1);
    // g.addnode(1, 2);
    // g.addnode(2, 3);
    // g.addnode(3, 0);
    // g.addnode(0, 2); 
//     5
// 0 1
// 0 4
// 1 2
// 2 4
// 2 3
// 3 4
    g.addnode(0, 1);
    g.addnode(0, 4);
    g.addnode(1, 2);
    g.addnode(2, 4);
    g.addnode(2, 3); 
    g.addnode(3, 4); 



    int m = 3; 

    if (g.isColorable(m, n)) {
        cout << "Graph can be colored with " << m << " colors.\n";
    } 
    else {
        cout << "Graph cannot be colored with " << m << " colors.\n";
    }

    return 0;
}
