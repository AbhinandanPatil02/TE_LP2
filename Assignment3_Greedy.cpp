#include<bits/stdc++.h>
using namespace std;


class graph{
    public:
    
    unordered_map<int,vector<pair<int,int>>>adjlist; //  1-> {2,3}    node is 2 and weight is 3

    void addnode(int u,int v,int wt){
        adjlist[u].push_back({v,wt});
        adjlist[v].push_back({u,wt});
    }

    int min_spanning_tree(int src,int n,vector<int>&mst){
        int cost=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // pair (wt,v)
        pq.push({0,src});
        vector<int>vis(n,0);
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int v=node.second;
            int wt=node.first;
            if(vis[v]==1)continue;
            vis[v]=1;
            cost+=wt;
            mst.push_back(v);
            for(auto &it:adjlist[v]){
                int nbr=it.first;
                int nbr_wt=it.second;
                if(vis[nbr]==0){
                    pq.push({nbr_wt,nbr});
                }
            }
        }
        return cost;

    }

};



void selection_sort(vector<int>&v){
    int n=v.size();
    for(int i=0;i<n;i++){
        int val=v[i];
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(val>v[j]){
                idx=j;
                val=v[j];
            }
        }
        swap(v[idx],v[i]);
    }
    
}






int main(){

    // graph g;
    // int n=4;
    // g.addnode(0,1,5);
    // g.addnode(1,2,6);
    // g.addnode(1,3,3);
    // g.addnode(2,3,2);
    // vector<int>mst;
    // cout<<"Wt of mst : "<<g.min_spanning_tree(0,n,mst);
    // cout<<endl;
    // for(auto i:mst)cout<<i<<" -> ";
    // cout<<endl;

    
    //    5
    // 0-----1
    //     5/  \ 3
    //      2---3
    //        2

    vector<int>v={2,1,8,4,5};
    selection_sort(v);
    for(auto i:v)cout<<i<<" ";
    cout<<endl;

    return 0;
}