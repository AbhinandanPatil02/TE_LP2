#include<bits/stdc++.h>
using namespace std;



class Graph{

    public:
    unordered_map<int,vector<pair<int,int>>>adj;
    void addnode(int u, int v,int wt){
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }


    void print(){
        for(auto i:adj){
            cout<<i.first<<" : -> {";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<") ";
            }
            cout<<" }"<<endl;
        }
    }

    int mst(int src,int n,vector<int>&ans){
        int cost=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,src}); //wt , v
        vector<int>vis(n,0);
        while(!q.empty()){
            auto node=q.top();
            q.pop();
            int wt=node.first;
            int v=node.second;
            if(vis[v]==1)continue;
            vis[v]=1;
            cost+=wt;
            ans.push_back(v);
            for(auto nbr:adj[v]){
                q.push({nbr.second,nbr.first});
            }
        }

        return cost;

    }




    void dijkstra(int src,int n,vector<int>&dist){
        dist.assign(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,src});
        dist[src]=0;
        while(!q.empty()){
            auto node=q.top();
            q.pop();
            int d=node.first;
            int u=node.second;
            if(d>dist[u])continue;
            for(auto nbr:adj[u]){
                if(dist[u]+nbr.second<dist[nbr.first]){
                    dist[nbr.first]=nbr.second+dist[u];
                    q.push({dist[nbr.first],nbr.first});
                }
            }
        }

    }



};


void selection_sort(vector<int>&v){
    for(int i=0;i<v.size();i++){
        int val=v[i];
        int idx=i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<val){
                idx=j;
                val=v[j];
            }
        }
        if(i!=idx)swap(v[idx],v[i]);
    }
}








int main(){

    Graph g;
    g.addnode(0,1,2);
    g.addnode(1,2,5);
    g.addnode(1,3,2);
    g.addnode(2,3,1);
    vector<int>ans;
    // cout<<"cost of mst "<<g.mst(0,4,ans)<<endl;
    // for(auto i:ans)cout<<i<<" ";
    // cout<<endl;
    vector<int>dist;
    int n=4;
    g.dijkstra(0,n,dist);
    for(auto i:dist)cout<<i<<" ";
    cout<<endl;
    

    // vector<int>v={2,4,0,3,9};
    // selection_sort(v);
    // for(auto i:v)cout<<i<<" ";

    return 0;
}