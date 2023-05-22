#include <iostream>
#include <climits>


#define INF INT_MAX

using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[n][n];
    cout << "Enter the adjacency matrix (use 999 for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << graph[i][j] << "\t";
            }
        }
        cout << endl;
    }

    return 0;
}