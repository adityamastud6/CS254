#include <bits/stdc++.h>
using namespace std;

const int V = 5;
bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
	colorArr[src] = 1;
	queue <int> q;
	q.push(src);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < V; ++v)
		{
			if (G[u][v] && colorArr[v] == -1){
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}
	return true;
}
bool isBipartite(int G[][V])
{
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;
	for (int i = 0; i < V; i++)
		if (colorArr[i] == -1)
			if (isBipartiteUtil(G, i, colorArr) == false)
				return false;

	return true;
}
bool canBeDividedinTwoCliques(int G[][V]){

	int GC[V][V];
	for (int i=0; i<V; i++)
		for (int j=0; j<V; j++)
			GC[i][j] = (i != j)? !G[i][j] : 0;
	return isBipartite(GC);
}

int main()
{
	int G[][V] = {{0, 1, 1, 1, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0}
	};

	canBeDividedinTwoCliques(G) ? cout << "Yes" :
								cout << "No";
	return 0;
}












// #include<bits/stdc++.h>
// using namespace std;

//     bool check(int start, int color, vector<int> &vis, vector<vector<int>> &graph){
//         vis[start] = color;
//         for(auto it:graph[start]){
//             if(vis[it] == -1){
//                 if(!check(it, !color, vis, graph))
//                     return false;
//             }
//             else if(vis[it] == color)
//                     return false;
//         }
//         return true;
//     }
    
//   bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> vis(n,-1);
//         for(int i=0;i<n;i++){
//             if(vis[i] == -1){
//                 if(!check(i,0,vis,graph))
//                     return false;
//             }
//         }
//         return true;
//     }

    
// int main(){
//     int v,e; cin>>v>>e;
//     vector<vector<int>>graph(v);
//     for(int i=0;i<e;i++){
//         int x,y;
//         cin>>x>>y;
//         graph[x].push_back(y);
//         graph[y].push_back(x);
//     }
//     vector<vector<int>>reverse(v);
//      vector<int>dummy(v,0);
//      for(int i=0;i<v;i++){
//         dummy[i]==1;
//          for(auto x:graph[i]){
//             dummy[x]=1;
//          }
//          for(int j=0;j<v;j++){
//               if(dummy[j]==0){
//                 reverse[i].push_back(j);
//                 reverse[j].push_back(i);
//               }
//          }
//          dummy.clear();
//      }
//      cout<<isBipartite(reverse)<<" Answer"<<endl;
//     return 0;
// }