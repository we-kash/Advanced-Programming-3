#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void dijkstra(vector<vector<pair<int, int>>> &adj, int src, vector<int> &dist) {
 int n = adj.size();
 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 dist[src] = 0;
 pq.push({0, src});
 while (!pq.empty()) {
 int u = pq.top().second;
 int d = pq.top().first;
 pq.pop();
 if (d > dist[u]) continue;
 for (auto [v, w] : adj[u]) {
 if (dist[u] + w < dist[v]) {
 dist[v] = dist[u] + w;
 pq.push({dist[v], v});
 }
 }
 }
}
int main() {
 int n = 10; // number of nodes
 vector<vector<pair<int, int>>> adj(n);
 // randomly generate edges with weights
 for (int i = 0; i < n; i++) {
 for (int j = i + 1; j < n; j++) {
 int w = rand() % 10 + 1; // random weight between 1 and 10
 adj[i].push_back({j, w});
 adj[j].push_back({i, w});
 }
 }
 // print the generated graph
 cout << "Generated Graph:\n";
 for (int i = 0; i < n; i++) {
 cout << i << ": ";
 for (auto [v, w] : adj[i]) {
 cout << "(" << v << ", " << w << ") ";
 }
 cout << "\n";
 }
 int src = 0; // source node
 vector<int> dist(n, INF); // distances from the source node
 dijkstra(adj, src, dist);
 // print the shortest distances from the source node
 cout << "Shortest Distances from Node " << src << ":\n";
 for (int i = 0; i < n; i++) {
 cout << i << ": " << dist[i] << "\n";
 }
 return 0;
}
