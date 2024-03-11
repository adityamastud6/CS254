#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    queue<int> Q;
    vector<int> deg(n+1), topological_sort;
 
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }
    
    for(int i = 1; i < n+1; ++i) 
        for(int x : adj[i]) deg[x]++;
    
    for(int i = 1; i < n+1; ++i) 
        if(!deg[i]) Q.push(i);
        
        
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        topological_sort.push_back(node);
        for(int child : adj[node]) {
            deg[child]--;
            if(!deg[child])
                Q.push(child);           
        }
    }
    
    for(int x : topological_sort) cout << x << ' ';
}