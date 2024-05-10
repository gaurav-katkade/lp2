#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Comparator for the priority queue
struct CompareEdges {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

// Modified Dijkstra's algorithm for finding the MST
vector<Edge> dijkstraMST(vector<vector<int>>& graph, int n, int source) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> distances(n, INT_MAX);
    priority_queue<Edge, vector<Edge>, CompareEdges> pq;

    // Start from the source node
    distances[source] = 0;
    pq.push(Edge(source, source, 0));

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        // If the vertex is not visited, add the edge to MST and visit it
        if (!visited[curr.v]) {
            visited[curr.v] = true;

            // Add all unvisited neighbors to the priority queue
            for (int i = 0; i < n; i++) {
                if (graph[curr.v][i] != 0 && !visited[i]) {
                    int weight = graph[curr.v][i];
                    pq.push(Edge(curr.v, i, weight));
                    if (weight < distances[i]) {
                        distances[i] = weight;
                        parent[i] = curr.v;
                    }
                }
            }
        }
    }

    // Construct the MST
    vector<Edge> mst;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            mst.push_back(Edge(parent[i], i, graph[i][parent[i]]));
        }
    }

    return mst;
}

int main() {
    int n = 6; // Number of vertices

    // Adjacency matrix representation of the graph
    vector<vector<int>> graph = {
        {0, 5, 0, 3, 0, 0},
        {5, 0, 2, 1, 0, 0},
        {0, 2, 0, 4, 6, 0},
        {3, 1, 4, 0, 7, 6},
        {0, 0, 6, 7, 0, 5},
        {0, 0, 0, 6, 5, 0}
    };

    int source = 0; // Start from vertex 0
    vector<Edge> mst = dijkstraMST(graph, n, source);

    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.u << " -- " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}



// #include <iostream>
// #include <vector>
// #include <queue>
// #include <limits>

// using namespace std;

// // Structure to represent a vertex with its distance
// struct Vertex {
//     int node, distance;
//     Vertex(int node, int distance) : node(node), distance(distance) {}
// };

// // Comparator for the priority queue
// struct CompareVertices {
//     bool operator()(const Vertex& a, const Vertex& b) {
//         return a.distance > b.distance;
//     }
// };

// // Dijkstra's algorithm for finding shortest paths
// vector<int> dijkstra(vector<vector<int>>& graph, int source, int n) {
//     vector<int> distances(n, numeric_limits<int>::max());
//     vector<bool> visited(n, false);
//     priority_queue<Vertex, vector<Vertex>, CompareVertices> pq;

//     // Start from the source node
//     distances[source] = 0;
//     pq.push(Vertex(source, 0));

//     while (!pq.empty()) {
//         Vertex curr = pq.top();
//         pq.pop();

//         // If the vertex is not visited, update the distances of its neighbors
//         if (!visited[curr.node]) {
//             visited[curr.node] = true;

//             // Update the distances of all unvisited neighbors
//             for (int i = 0; i < n; i++) {
//                 if (graph[curr.node][i] != 0 && !visited[i]) {
//                     int distance = graph[curr.node][i] + curr.distance;
//                     if (distance < distances[i]) {
//                         distances[i] = distance;
//                         pq.push(Vertex(i, distance));
//                     }
//                 }
//             }
//         }
//     }

//     return distances;
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

//     int source = 0; // Start from vertex 0
//     vector<int> distances = dijkstra(graph, source, n);

//     cout << "Shortest distances from source vertex " << source << ":" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << "Vertex " << i << ": " << distances[i] << endl;
//     }

//     return 0;
// }