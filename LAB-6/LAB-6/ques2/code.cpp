#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(const vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue; // Skip if we've found a shorter path already

        for (const auto& edge : graph[u]) {
            int v = edge.second;
            int w = edge.first;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m; // Number of vertices, number of edges
    cin >> n >> m;

    vector<vector<pii>> graph(n); // Adjacency list representation

    // Read the edges
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // 0-based indexing
        // Multiply the edge weight by -1
        graph[u].push_back({-w, v});
    }

    // Run Dijkstra's algorithm from each vertex
    vector<vector<int>> longest_paths(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        vector<int> dist = dijkstra(graph, i);
        for (int j = 0; j < n; ++j) {
            // Multiply back the distances by -1 to get the longest path
            longest_paths[i][j] = -dist[j];
        }
    }

    // Print the longest paths
    cout << "Longest paths between any two vertices:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (longest_paths[i][j] == INF)
                cout << "INF ";
            else
                cout << longest_paths[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
