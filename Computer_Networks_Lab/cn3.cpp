// Link State Routing

#include <bits/stdc++.h>
using namespace std;

#define INF 9999
#define N 5

int main() {
    char nodes[N] = {'A', 'B', 'C', 'D', 'E'};

    int graph[N][N] = {
        {0,   2,   INF, 1,   INF},
        {2,   0,   3,   2,   INF},
        {INF, 3,   0,   INF, 1},
        {1,   2,   INF, 0,   1},
        {INF, INF, 1,   1,   0}
    };

    char source;
    cout << "Enter source node (A-E): ";
    cin >> source;

    int src = source - 'A';

    vector<int> dist(N, INF);
    vector<bool> visited(N, false);

    dist[src] = 0;

    // Dijkstra's Algorithm (Link State Routing)
    for (int count = 0; count < N - 1; count++) {

        int u = -1;
        int minDist = INF;

        // Find unvisited node with minimum distance
        for (int i = 0; i < N; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // Update distances of neighbors
        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest paths from node " << source << " (Link State Routing):\n";
    for (int i = 0; i < N; i++) {
        cout << "To " << nodes[i] << " -> ";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
