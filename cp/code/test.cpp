#include<bits/stdc++.h>
using namespace std;
vector<vector<std::array<int,2>>> adj;
int n;
vector<int> nodes;
vector<int> par(n,0);
int find(int i){
    if(par[i]==i){
        return i;
    }
    return par[i] = find(par[i]);
}
void join(int i, int j){
    par[find(i)] = find(j);
}
void dijk(){
    vector<int> dists(n,INT_MAX);
    set<int> unvis(nodes.begin(),nodes.end());
    int s,t,u;
    dists[s] = 0;
    unvis.erase(s);
    u = s;
    while(true){
        for(std::array<int,2> &nb:adj[u]){
            // int v = nb[0],wt = nb[1];
            // dists[v] = min(dists[v],dists[u]+wt);
        }
        int minunvis = *unvis.begin();
        for(int v:unvis){
            if(dists[v] < dists[minunvis]){
                minunvis = v;
            }
        }
        u = minunvis;
        unvis.erase(u);
        
    }
}
int kruskal(){
    //pick min wt edge everytime.
    vector<vector<int>> edges;//[wt,u,v][], sorted by wt descending.
    for(int i=0;i<n;i++){
        par[i] = i;
    }
    int count = 0;
    int wtsum = 0;
    while(count<n-1){
        vector<int> edge = edges.back();
        if(find(edge[1])!=find(edge[2])){
            join(edge[1],edge[2]);
            count++;
            wtsum +=edge[0];
        }
        edges.pop_back();
    }
    return wtsum;
}
int prims(){
    //connect a neighbour of least cost.
    int s = 0;
    vector<bool> vis(n,false);
    set<int> nbs;
    vis[s] = true;
    int count = 0;
    int wtsum = 0;
    while(count<n-1){
        // for(array<int,2> nb:adj())
    }
    return wtsum;
}
int main(){
    
}