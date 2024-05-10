#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Find the root of a node in the disjoint set
int findRoot(int parent[], int x) {
    if (parent[x] == -1)
        return x;
    return parent[x] = findRoot(parent, parent[x]); // Path compression
}

// Union of two sets
void unionSets(int parent[], int x, int y) {
    int xRoot = findRoot(parent, x);
    int yRoot = findRoot(parent, y);
    parent[xRoot] = yRoot;
}

// Kruskal's algorithm for finding the MST
void kruskalMST(Edge edges[], int n, int V) {
    // Sort edges by weight
    sort(edges, edges + n, compareEdges);

    // Initialize parent array for disjoint set
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    Edge mst[V - 1];
    int mstCount = 0;

    for (int i = 0; i < n; i++) {
        int u = findRoot(parent, edges[i].u);
        int v = findRoot(parent, edges[i].v);

        // If the two nodes are in different sets, add the edge to MST
        if (u != v) {
            mst[mstCount++] = edges[i];
            unionSets(parent, u, v);
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 0; i < mstCount; i++) {
        cout << mst[i].u << " -- " << mst[i].v << " : " << mst[i].weight << endl;
    }
}

int main() {
    int V = 6; // Number of vertices
    Edge edges[] = {
        {0, 1, 5},
        {0, 3, 3},
        {1, 3, 1},
        {1, 2, 2},
        {3, 2, 4},
        {2, 4, 6},
        {4, 5, 5},
        {3, 5, 6},
        {3, 4, 7}
    };

    int n = sizeof(edges) / sizeof(edges[0]);

    kruskalMST(edges, n, V);

    return 0;
}