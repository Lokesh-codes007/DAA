#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
// {weight, vertex}

void primMST(int V, vector<vector<pii>>& adj) {
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);

    priority_queue<
        pii,
        vector<pii>,
        greater<pii>
    > pq;

    key[0] = 0;
    pq.push({0, 0});

    int totalWeight = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        totalWeight += weight;

        for (auto edge : adj[u]) {
            int edgeWeight = edge.first;
            int v = edge.second;

            if (!visited[v] && edgeWeight < key[v]) {
                key[v] = edgeWeight;
                parent[v] = u;
                pq.push({edgeWeight, v});
            }
        }
    }

    cout << "Edges in Prim MST:\n";

    for (int i = 1; i < V; i++) {
        if (parent[i] == -1) {
            cout << "Graph is not connected.\n";
            return;
        }

        cout << parent[i] << " - "
             << i << " : "
             << key[i] << "\n";
    }

    cout << "Total MST Weight: "
         << totalWeight << "\n";
}

int main() {
    int V = 5;

    vector<vector<pii>> adj(V);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    };

    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    primMST(V, adj);

    return 0;
}