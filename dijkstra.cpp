#include <iostream>
#include <climits>
using namespace std;

void dij(int source, int cost[][20], int visited[], int d[], int n) {
    int i, j, min, u, w;
    for(i = 1; i <= n; i++) {
        visited[i] = 0;
        d[i] = cost[source][i];
    }
    visited[source] = 1;
    d[source] = 0;
    for(j = 2; j <= n; j++) {
        min = INT_MAX;
        for(i = 1; i <= n; i++) {
            if(visited[i] != 1) {
                if (d[i] < min) {
                    min = d[i];
                    u = i;
                }
            }
        }
        visited[u] = 1;
        for(w = 1; w <= n; w++) {
            if(cost[u][w] != -1 && visited[w] == 0) { // Modified condition to handle weighted connected graph
                if(d[w] > cost[u][w] + d[u])
                    d[w] = cost[u][w] + d[u];
            }
        }
    }
}

int main() {
    int cost[20][20], visited[20], d[20];
    int i, j, n, source;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the cost adjacency matrix:\n";
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }
    cout << "Enter the source node: ";
    cin >> source;
    dij(source, cost, visited, d, n);
    for(i = 1; i <= n; i++) {
        if(i != source)
            cout << "Shortest path from " << source << " to " << i << " is " << d[i] << endl;
    }
    return 0;
}
