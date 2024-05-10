#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Function to add an edge to the graph
    void DFS(int v); // DFS traversal from a given vertex v
    void DFSUtil(int v, vector<bool> &visited); // A function used by DFS
    void BFS(int s); // BFS traversal from a given source s
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Since the graph is undirected
}

void Graph::DFSUtil(int v, vector<bool> &visited) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

void Graph::DFS(int v) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

void Graph::BFS(int s) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent has not been visited, then mark it visited and enqueue it
        for (int i : adj[s]) {
            if (!visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

// Driver code
int main() {
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);

    cout << "\nBreadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
