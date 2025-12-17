// Distance Vector Routing

#include <bits/stdc++.h>
using namespace std;

#define INF 9999
#define N 5

int main() {
    char nodes[N] = {'A', 'B', 'C', 'D', 'E'};

    int cost[N][N] = {
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
    dist[src] = 0;

    // Distance Vector (Bellman-Ford) Algorithm
    for (int i = 0; i < N - 1; i++) {
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                if (cost[u][v] != INF && dist[u] != INF &&
                    dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                }
            }
        }
    }

    cout << "\nShortest paths from node " << source << ":\n";
    for (int i = 0; i < N; i++) {
        cout << "To " << nodes[i] << " -> ";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
