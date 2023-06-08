
#include <bits/stdc++.h>
using namespace std;

#define V 6 // Define the number of vertices in the graph

void primMST(int graph[V][V], int startNode) {
    vector<int> key(V, INT_MAX); // Initialize a vector to store the weight of each vertex, initially set to infinity
    vector<bool> mstSet(V, false); // Initialize a vector to track which vertices have been added to the MST, initially set to false
    vector<int> parent(V, -1); // Initialize a vector to store the parent of each vertex in the MST, initially set to -1

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Create a priority queue to store edges sorted by weight
    
    pq.push(make_pair(0, startNode)); // Push the starting node onto the priority queue with a weight of 0
    key[startNode] = 0; 

    while (!pq.empty()) { // Start the MST algorithm
        int u = pq.top().second; // Get the next vertex with the minimum weight
        pq.pop(); 

        if (mstSet[u]) // If the vertex has already been added to the MST, continue to the next iteration
            continue;

        mstSet[u] = true; // Mark the vertex as added to the MST

        for (int v = 0; v < V; v++) { 
            int weight = graph[u][v]; // Get the weight of the edge between the current vertex and the adjacent vertex

            if (weight && !mstSet[v] && weight < key[v]) { // If there is an edge, the adjacent vertex has not been added to the MST, and the weight of the edge is less than the current weight of the adjacent vertex
                parent[v] = u; 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); // Add the adjacent vertex to the priority queue with its updated weight
            }
        }
    }

    cout << "Edge  \t      Weight\n"; 
    for (int i = 1; i < V; i++)
        cout << parent[i] << " -- " << i << "  \t  " << key[i] << endl;
}

int main() {
    int adjacencyMatrix[V][V] = {{0, 3, 0, 0, 0, 1},
                                 {3, 0, 2, 1, 10, 0},
                                 {0, 2, 0, 3, 0, 5},
                                 {0, 1, 3, 0, 5, 0},
                                 {0, 10, 0, 5, 0, 4},
                                 {1, 0, 5, 0, 4, 0}};

    primMST(adjacencyMatrix, 0); 

    return 0; 
}