#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9; // a large constant representing infinity
int n; // number of vertices
vector<vector<int>> cap; // capacity matrix
vector<vector<int>> adj; // adjacency list
int augment(int u, int t, int f, vector<bool>& visited) {
 if (u == t) {
 return f;
 }
 visited[u] = true;
 for (int v : adj[u]) {
 if (!visited[v] && cap[u][v] > 0) {
 int df = augment(v, t, min(f, cap[u][v]), visited);
 if (df > 0) {
 cap[u][v] -= df;
 cap[v][u] += df;
 return df;
 }
 }
 }
 return 0;
}
int max_flow(int s, int t) {
 int flow = 0;
 while (true) {
 vector<bool> visited(n, false);
 int df = augment(s, t, INF, visited);
 if (df == 0) {
 break;
 }
 flow += df;
 }
 return flow;
}
int main() {
 n = 6; // number of vertices
 cap.assign(n, vector<int>(n, 0)); // initialize capacity matrix to 0
 adj.resize(n); // initialize adjacency list
 // add edges to the graph
 adj[0] = {1, 2};
 adj[1] = {2, 3};
 adj[2] = {3, 4};
 adj[3] = {4};
 adj[4] = {1, 5};
 adj[5] = {4};
 cap[0][1] = 10;
 cap[0][2] = 10;
 cap[1][2] = 2;
 cap[1][3] = 4;
 cap[2][3] = 9;
 cap[3][4] = 10;
 cap[4][1] = 6;
 cap[4][5] = 10;
 int s = 0; // source
 int t = 5; // sink
 int flow = max_flow(s, t);
 cout << "Maximum flow: " << flow << "\n";
 return 0;
}