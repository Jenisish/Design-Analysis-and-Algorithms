#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

const int MAX = 15; // maximum number of cities
int graph[MAX][MAX]; // adjacency matrix for the graph
int memo[MAX][1 << MAX]; // memoization table
int n; // number of cities

// TSP function using dynamic programming
int tsp(int pos, int bitmask, vector<int>& path) {
    if (bitmask == (1 << n) - 1) { // base case: all cities visited
        path.push_back(0); // add starting city to the path
        return graph[pos][0]; // return to starting city
    }

    if (memo[pos][bitmask] != -1) { // if already computed
        return memo[pos][bitmask]; // return memoized value
    }

    int ans = INT_MAX;
    int next_city = -1; // variable to store the next city in the shortest path
    for (int nxt = 0; nxt < n; nxt++) { // try all unvisited cities
        if (!(bitmask & (1 << nxt))) { // if city is not visited
            int cost = graph[pos][nxt] + tsp(nxt, bitmask | (1 << nxt), path);
            if (cost < ans) {
                ans = cost;
                next_city = nxt;
            }
        }
    }

    if (next_city != -1) { // add next city to the path
        path.push_back(next_city);
    }

    return memo[pos][bitmask] = ans; // memoize and return
}

int main() {
    // input graph
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // initialize memoization table to -1
    memset(memo, -1, sizeof(memo));

    // compute shortest path
    vector<int> path;
    int ans = tsp(0, 1, path); // start at city 0, bitmask for visited cities is 1

    // output shortest path
    cout << "Shortest path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    cout << "Shortest path cost: " << ans << endl;

    return 0;
}
