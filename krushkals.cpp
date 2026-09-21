#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (rank[px] < rank[py])
            swap(px, py);

        parent[py] = px;

        if (rank[px] == rank[py])
            rank[px]++;

        return true;
    }
};

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    DSU dsu(V);

    int totalWeight = 0;
    int edgeCount = 0;

    cout << "Edges in Kruskal MST:\n";

    for (Edge edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            cout << edge.u << " - "
                 << edge.v << " : "
                 << edge.weight << "\n";

            totalWeight += edge.weight;
            edgeCount++;

            if (edgeCount == V - 1)
                break;
        }
    }

    if (edgeCount != V - 1) {
        cout << "Graph is not connected.\n";
        return;
    }

    cout << "Total MST Weight: "
         << totalWeight << "\n";
}

int main() {
    int V = 5;

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    kruskalMST(V, edges);

    return 0;
}