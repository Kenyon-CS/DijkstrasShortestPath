#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int V = 9;  // Number of vertices in the graph
const int INF = numeric_limits<int>::max();  // Define infinity as the maximum int value

// A utility function to print the distance array
void printSolution(const vector<int>& dist) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << "\n";
    }
}

// Function to implement Dijkstra's algorithm using a priority queue
void dijkstra(const vector<vector<int>>& graph, int src) {
    // Initialize distances from src to all other vertices as infinite
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Priority queue to select the vertex with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});  // Push the source with a distance of 0

    // While there are vertices in the priority queue
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Update distance values of adjacent vertices of the dequeued vertex
        for (int v = 0; v < V; v++) {
            // Only consider vertices that are reachable and not yet finalized
            if (graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});  // Push updated distance to the queue
            }
        }
    }

    // Print the calculated shortest distances
    printSolution(dist);
}

// Driver code
int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    // Execute Dijkstra's algorithm from source vertex 0
    dijkstra(graph, 0);

    return 0;
}
