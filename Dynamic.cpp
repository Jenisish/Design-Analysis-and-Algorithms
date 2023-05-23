#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

const int MAX = 15; 
int graph[MAX][MAX]; 
int memo[MAX][1 << MAX];
int n; 

int tsp(int pos, int bitmask, vector<int>& path) {
    if (bitmask == (1 << n) - 1) { 
        path.push_back(0); 
        return graph[pos][0];
    }

    if (memo[pos][bitmask] != -1) { 
        return memo[pos][bitmask]; 
    }

    int ans = INT_MAX;
    int next_city = -1; 
    for (int nxt = 0; nxt < n; nxt++) { 
        if (!(bitmask & (1 << nxt))) { 
            int cost = graph[pos][nxt] + tsp(nxt, bitmask | (1 << nxt), path);
            if (cost < ans) {
                ans = cost;
                next_city = nxt;
            }
        }
    }

    if (next_city != -1) { 
        path.push_back(next_city);
    }

    return memo[pos][bitmask] = ans;
}

int main() {
   
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    
    memset(memo, -1, sizeof(memo));

   
    vector<int> path;
    int ans = tsp(0, 1, path); 


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
