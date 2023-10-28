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
struct Boy{
    int h=0;
    int iq=0;
};
struct BoyComp{
    bool operator()(Boy b1, Boy b2)const{
        return b1.h<b2.h;
    }
};
bool compByIQ(const Boy&b1, const Boy&b2){
    return b1.iq<b2.iq;
}
int main(){
    srand(0);
    // set<Boy,decltype(compByIQ)*> boys(compByIQ);
    // set<Boy,BoyComp> boys(compByIQ);
    // vector<Boy> boys;
    priority_queue<Boy,vector<Boy>,decltype(compByIQ)*> boys(compByIQ);
    for(int i=0;i<4;i++){
        Boy boy = {rand(),rand()};
        // boys.insert(boy);
        // boys.push_back(boy);
        boys.push(boy);
    }
    // sort(boys.begin(),boys.end(),BoyComp());
    // for(const Boy& boy:boys){
    //     cout<<"{"<<boy.h<<","<<boy.iq<<"}"<<endl;
    // }
    while(boys.size()){
        Boy boy = boys.top();
        cout<<"{"<<boy.h<<","<<boy.iq<<"}"<<endl;
        boys.pop();
    }
}

