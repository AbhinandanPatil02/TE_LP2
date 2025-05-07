#include<bits/stdc++.h>
using namespace std;



class Graph{
    public:
    unordered_map<int,vector<int>>adj;
    void addnode(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print(){
        for(auto i:adj){
            cout<<i.first<<"-> {";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<" }"<<endl;
        }
    }

    vector<int>bfs(int src,int n){

        queue<int>q;
        q.push(src);
        vector<int>vis(n,0);
        vis[0]=1;
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto nbr:adj[node]){
                if(vis[nbr]==0){
                    vis[nbr]=1;
                    q.push(nbr);
                }
            }
        }
        return ans;
    }

    void dfs(int src,vector<int>&vis,vector<int>&ans){
        vis[src]=1;
        ans.push_back(src);
        for(auto nbr:adj[src]){
            if(vis[nbr]==0){
                dfs(nbr,vis,ans);
            }
        }
    }


    void bfsrec(vector<int>&ans,vector<int>&vis,int src,queue<int>&q){
        if(q.empty())return ;
        ans.push_back(src);
        q.pop();
        for(auto nbr:adj[src]){
            if(vis[nbr]==0){
                vis[nbr]=1;
                q.push(nbr);
                bfsrec(ans,vis,nbr,q);
            }
        }
    }

    void bfs_rec(vector<int>&vis,queue<int>q){
        if(q.empty())return;
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto nbr:adj[node]){
            if(vis[nbr]==0){
                q.push(nbr);
                vis[nbr]=1;
            }
        }
        bfs_rec(vis,q);
    }

    


};




int main(){
    Graph g;
    int n=6;
    g.addnode(0,1);
    g.addnode(0,3);
    g.addnode(1,2);
    g.addnode(1,4);
    g.addnode(5,5);
    vector<int>bfs;
    g.print();
    bfs= g.bfs(0,n);
    vector<int>vis(n,0);
    vector<int>dfs;
    g.dfs(0,vis,dfs);
    cout<<"Printing BFS : ";
    for(auto i:bfs)cout<<i<<" ";
    cout<<endl;
    cout<<"Printing DFS : ";
    for(auto i:dfs)cout<<i<<" ";
    cout<<endl;
    queue<int>q;
    vector<int>bfsr;
    vector<int>visr(n,0);
    q.push(0);
    visr[0]=1;
    g.bfsrec(bfsr,visr,0,q);
    cout<<"Printing BFS recursive : ";
    for(auto i:bfsr)cout<<i<<" ";
    
    return 0;
}