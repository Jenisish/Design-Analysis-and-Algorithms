#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent[parent[node]], parent);
}

void kruskalsAlgorithm(vector<Edge>& edges, int n) {
   
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;
    int mstWeight = 0;

    for (auto edge : edges) {
        int parent1 = findParent(edge.src, parent);
        int parent2 = findParent(edge.dest, parent);
        if (parent1 != parent2) {
            mst.push_back(edge);
            mstWeight += edge.weight;
            parent[parent1] = parent[parent2];
        }
    }

    cout << "Edges in the MST:" << endl;
    for (auto edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    cout << "Total weight of the MST: " << mstWeight << endl;
}


int main() {

    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<Edge> edges(2 * m);

    cout << "Enter the source, destination, and weight of each edge: \n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        edges[m + i].src = edges[i].dest;
        edges[m + i].dest = edges[i].src;
        edges[m + i].weight = edges[i].weight;
    }

    kruskalsAlgorithm(edges, n);

    return 0;
}
