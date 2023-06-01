#include <iostream>
#include <climits>

#define max 6

using namespace std;

void dijkstra(int G[max][max], int Vertice_Count, int start_node) {
    int distancefromNode[max];
    bool visited[max];

    // Initialize all distances as infinity and visited array as false
    for (int i = 0; i < Vertice_Count; i++) {
        distancefromNode[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance of starting node from itself is always 0
    distancefromNode[start_node] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < Vertice_Count-1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = -1;
        for (int v = 0; v < Vertice_Count; v++) {
            if (!visited[v] && (u == -1 || distancefromNode[v] < distancefromNode[u])) {
                u = v;
            }
        }

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update distancefromNode value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < Vertice_Count; v++) {
            if (G[u][v] && !visited[v] && distancefromNode[u] != INT_MAX && distancefromNode[u] + G[u][v] < distancefromNode[v]) {
                distancefromNode[v] = distancefromNode[u] + G[u][v];
            }
        }
    }

    // Print the calculated shortest distances and average time 
    float total=0;
    cout << "Vertex\t\t Shortest time from source node: "<<start_node<<"\n" ;
    for (int i = 0; i < Vertice_Count; i++) {
        
        if (distancefromNode[i] == INT_MAX) {
            cout << i << "\t\tINFINITY\n";
        } else {
            cout << i << "\t\t\t" << distancefromNode[i] << endl;
            total += distancefromNode[i];
        }
    }
    cout << "------------------------------"<< endl;
    cout << "Average Time  : \t" <<total/(Vertice_Count-1);
}

int main(){
    int G[max][max] ={{0,10,0,0,15,5},
                      {10,0,10,30,0,0},
                      {0,10,0,12,5,0},
                     {0,30,12,0,0,20},
                      {15,0,5,0,0,0},
                     {5,0,0,20,0,0}};

    int Vertice_Count = 6;
    int startingNode = 5;
    dijkstra(G,Vertice_Count,startingNode);

return 0;
}