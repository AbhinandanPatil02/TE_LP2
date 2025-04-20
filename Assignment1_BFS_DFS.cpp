#include<bits/stdc++.h>
using namespace std;


class graph{
    public:
    
    unordered_map<int,vector<int>>adjlist;

    void addnode(int u,int v){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<int> bfs(int src,int n){
        queue<int>q;
        vector<int>vis(n+1,0);
        vector<int>ans;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:adjlist[node]){
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
        for(auto nbr:adjlist[src]){
            if(vis[nbr]==0){
                dfs(nbr,vis,ans);
            }
        }
    }



};


int main(){

    graph g;
    int n=4;
    g.addnode(0,1);
    g.addnode(1,2);
    g.addnode(1,3);
    g.addnode(2,3);
    g.addnode(2,4);

    vector<int>bfs=g.bfs(0,n);
    for(auto i:bfs)cout<<i<<" ";
    cout<<endl;
    vector<int>vis(n+1,0);
    vector<int>dfs;
    g.dfs(0,vis,dfs);
    for(auto i:dfs)cout<<i<<" ";


    
    return 0;
}