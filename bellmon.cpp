#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int vertex, int start, vector<vector<int>> graph) {
    vector<int> dist(vertex, 1e8);
    dist[start] = 0;

    for (int j = 0; j < vertex - 1; j++) {
        for (auto it : graph) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto it : graph) {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle found" << endl;
        }
    }

    return dist;
}

int main() {
    int n;
    cout << "Enter the number of edges: ";
    cin >> n;
    int vertex;
    cout << "Enter the number of vertices: ";
    cin >> vertex;

    vector<vector<int>> graph(n, vector<int>(3));
    cout << "Enter the edges (u, v, w):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }

    cout << "The graph is:" << endl;
    for (int j = 0; j < n; j++) {
        cout << graph[j][0] << " " << graph[j][1] << " " << graph[j][2] << endl;
    }

    vector<int> dist = bellmanFord(vertex, 0, graph);
    cout << "Shortest distances from the start vertex:" << endl;
    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << endl;
    }

    return 0;
}
