#include <bits/stdc++.h>
using namespace std;
int main() {
 int n = 6; // number of vertices
 vector<vector<int>> adj(n); // adjacency list
 // add edges to the graph
 adj[0] = {1, 2, 3};
 adj[1] = {0, 2};
 adj[2] = {0, 1, 3, 4};
 adj[3] = {0, 2, 4, 5};
 adj[4] = {2, 3, 5};
 adj[5] = {3, 4};
 vector<int> colors(n, -1); // -1 means the vertex is uncolored
 vector<int> available_colors(n, 0); // available colors for each vertex
 for (int i = 0; i < n; i++) {
 // find the first available color for the current vertex
 for (int j : adj[i]) {
 if (colors[j] != -1) {
 available_colors[colors[j]] = 1;
 }
 }
 int color;
 for (color = 0; color < n; color++) {
 if (available_colors[color] == 0) {
 break;
 }
 }
 colors[i] = color;
 // reset the available colors for the next vertex
 for (int j : adj[i]) {
 if (colors[j] != -1) {
 available_colors[colors[j]] = 0;
 }
 }
 }
 // print the colors of the vertices
 for (int i = 0; i < n; i++) {
 cout << "Vertex " << i << " is colored with " << colors[i] << "\n";
 }
 return 0;
}