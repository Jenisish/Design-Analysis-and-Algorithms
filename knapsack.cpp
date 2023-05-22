#include <iostream>
#include<vector>
using namespace std;

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n, bool selected[]) {
    int i, w;
    int K[n+1][W+1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w && val[i-1] + K[i-1][w-wt[i-1]] > K[i-1][w]) {
                K[i][w] = val[i-1] + K[i-1][w-wt[i-1]];
                selected[i-1] = true;  // Set selected flag for the current item
            }
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    int val[n], wt[n];
    bool selected[n];  // Initialize selected array to false
    selected[n]=false;
    cout << "Enter the weight of item " << endl;
    for (int i = 0; i < n; i++) { 
        cin >>wt[i];
   }
    
    cout << "Enter the value of item "<<endl;
    for (int i = 0; i < n; i++) { 
        cin>> val[i];
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    int result = knapsack(W, wt, val, n, selected);
    cout << "The maximum value that can be obtained is: " << result << endl;

    cout << "Selected items: ";
    for (int i = 0; i < n; i++) {
        cout << selected[i] << " ";
    }
    cout << endl;

    return 0;
}