#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10; // Maximum number of vertices in the graph
int graph[MAX][MAX]; // Adjacency matrix of the graph
int path[MAX]; // Path array to store the Hamiltonian Cycle
bool visited[MAX]; // Boolean array to mark visited vertices

// Function to print the Hamiltonian Cycle
void printSolution(int n) {
    cout << "Hamiltonian Cycle: ";
    for (int i = 0; i < n; i++) {
        cout << path[i] << " ";
    }
    cout << path[0] << endl;
}

// Function to check if it is safe to add a vertex to the path
bool isSafe(int v, int pos, int n) {
    // Check if the vertex v can be added to the path
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been visited
    if (visited[v])
        return false;

    return true;
}

// Function to find all Hamiltonian Cycles using backtracking
void hamiltonianCycleUtil(int pos, int n, int count) {
    // Base case: If all vertices are included in the path
    if (pos == n) {
        // Check if there is an edge from the last vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            printSolution(n);
            return;
        }
    }

    // Try different vertices as the next candidate in the path
    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos, n)) {
            path[pos] = v;
            visited[v] = true;
            hamiltonianCycleUtil(pos + 1, n, count + 1);
            visited[v] = false; // Backtrack
        }
    }
}

// Function to find all Hamiltonian Cycles in a graph
void findHamiltonianCycles(int n) {
    memset(visited, false, sizeof(visited)); // Initialize visited array to false
    memset(path, -1, sizeof(path)); // Initialize path array to -1

    // Start from each vertex as the first vertex in the path
    for (int i = 0; i < n; i++) {
        path[0] = i;
        visited[i] = true;
        hamiltonianCycleUtil(1, n, 1);
        visited[i] = false;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Create a graph represented as an adjacency matrix
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Finding Hamiltonian Cycles..." << endl;
    findHamiltonianCycles(n);

    return 0;
}