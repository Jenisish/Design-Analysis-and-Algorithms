#include <iostream>
#include <climits>

#define vertices 5  /* Define the number of vertices in the graph */

using namespace std;
int minimum_key(int k[], bool mst[]) {
    int minimum = INT_MAX, min, i;

    /* Iterate over all vertices to find the vertex with minimum key-value */
    for (i = 0; i < vertices; i++)
        if (!mst[i] && k[i] < minimum)
            minimum = k[i], min = i;
    return min;
}

void prim(int g[vertices][vertices]) {
    int parent[vertices];
    int k[vertices];
    bool mst[vertices];
    int i, count, edge, v; /* Here 'v' is the vertex */
    for (i = 0; i < vertices; i++) {
        k[i] = INT_MAX;
        mst[i] = false;
    }
    k[0] = 0; /* It selects the first vertex */
    parent[0] = -1; /* Set the first value of parent[] array to -1 to make it the root of MST */
    for (count = 0; count < vertices - 1; count++) {
        /* Select the vertex having minimum key and that is not added in the MST yet from the set of vertices */
        edge = minimum_key(k, mst);
        mst[edge] = true;
        for (v = 0; v < vertices; v++) {
            if (g[edge][v] && !mst[v] && g[edge][v] < k[v]) {
                parent[v] = edge;
                k[v] = g[edge][v];
            }
        }
    }
    /* Print the constructed Minimum Spanning Tree */
    cout << "Edge \tWeight\n";
    for (i = 1; i < vertices; i++)
        cout << parent[i] << " <-> " << i << "\t" << g[i][parent[i]] << std::endl;
}

int main() {
    int g[vertices][vertices];
    
    cout << "Enter the adjacency matrix for the graph (5x5):\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cin >> g[i][j];
        }
    }
    
    prim(g);
    return 0;
}
