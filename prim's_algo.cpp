#include <iostream>
#include <climits>

using namespace std;

// Number of vertices
#define V 6

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Prim's algorithm for finding the MST
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the MST
    int key[V];     // Key values used to pick minimum weight edge
    bool mstSet[V]; // Set to track vertices in the MST

    // Initialize all keys as INFINITE and mstSet as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;     // Make key value of the first vertex as 0
    parent[0] = -1; // First node is always the root

    // Construct the MST
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key values and parent index of adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i << " : " << graph[i][parent[i]] << endl;
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 5, 0, 3, 0, 0},
        {5, 0, 2, 1, 0, 0},
        {0, 2, 0, 4, 6, 0},
        {3, 1, 4, 0, 7, 6},
        {0, 0, 6, 7, 0, 5},
        {0, 0, 0, 6, 5, 0}
    };

    primMST(graph);

    return 0;
}




// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// // Structure to represent an edge
// struct Edge {
//     int u, v, weight;
//     Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
// };

// // Comparator function for the priority queue
// struct CompareEdges {
//     bool operator()(const Edge& a, const Edge& b) {
//         return a.weight > b.weight;
//     }
// };

// // Prim's algorithm for finding the MST
// vector<Edge> primMST(vector<vector<int>>& graph, int n) {
//     vector<bool> visited(n, false);
//     vector<Edge> mst;
//     priority_queue<Edge, vector<Edge>, CompareEdges> pq;

//     // Start from the first vertex
//     visited[0] = true;
//     for (int i = 0; i < n; i++) {
//         if (graph[0][i] != 0) {
//             pq.push(Edge(0, i, graph[0][i]));
//         }
//     }

//     while (!pq.empty()) {
//         Edge curr = pq.top();
//         pq.pop();

//         // If the vertex is not visited, add the edge to MST and visit it
//         if (!visited[curr.v]) {
//             visited[curr.v] = true;
//             mst.push_back(curr);

//             // Add all unvisited neighbors to the priority queue
//             for (int i = 0; i < n; i++) {
//                 if (graph[curr.v][i] != 0 && !visited[i]) {
//                     pq.push(Edge(curr.v, i, graph[curr.v][i]));
//                 }
//             }
//         }
//     }

//     return mst;
// }

// int main() {
//     int n = 6; // Number of vertices

//     // Adjacency matrix representation of the graph
//     vector<vector<int>> graph = {
//         {0, 5, 0, 3, 0, 0},
//         {5, 0, 2, 1, 0, 0},
//         {0, 2, 0, 4, 6, 0},
//         {3, 1, 4, 0, 7, 6},
//         {0, 0, 6, 7, 0, 5},
//         {0, 0, 0, 6, 5, 0}
//     };

//     vector<Edge> mst = primMST(graph, n);

//     cout << "Minimum Spanning Tree:" << endl;
//     for (const Edge& edge : mst) {
//         cout << edge.u << " -- " << edge.v << " : " << edge.weight << endl;
//     }

//     return 0;
// }