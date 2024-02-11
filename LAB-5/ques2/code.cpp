#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int edges; cin >> edges;
    vector<int>end(n+1, -1);
    while(edges--){
        int u, v; cin >> u >> v;
        end[u] = v;
    }
    queue<int>q;
    vector<int>moves(n+1, -1);
    q.push(1);
    moves[1] = 0;
    while(q.size() > 0){
        int u = q.front();
        q.pop();
        for(int j = 1; j <= 6; j++){
            int v = u+j;
            if(u+j > n){
                break;
            }
            while(end[v] != -1){
                v = end[v];
            }
            if(moves[v] == -1){
                q.push(v);
                moves[v] = moves[u]+1;
            }
        }
        if(moves[n] != -1){
            break;
        }
    }
    cout << moves[n] << endl;
}
