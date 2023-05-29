#include <iostream>
using namespace std;
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(wt[i-1] <= j) dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of knapsack: ";
    cin >> W;
    int wt[n];
    int val[n];
    cout << "Enter the weight and value of each item: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    cout << "Maximum value that can be obtained is: " << knapsack(W, wt, val, n) << endl;
    return 0;
}