#include <iostream>
using namespace std;

bool foundSolution = false;

void findSubsetSum(int set[], int n, int target, int current[], int index, int currentSum) {
    if (currentSum == target) {
        // Found a subset with the target sum
        foundSolution = true;
        cout << "Subset found: ";
        for (int i = 0; i < index; i++) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }

    if (index >= n || currentSum > target) {
        // Reached end of array or current sum exceeds target
        return;
    }

    // Include the current element and recurse
    current[index] = set[index];
    findSubsetSum(set, n, target, current, index + 1, currentSum + set[index]);

    // Exclude the current element and recurse
    current[index] = 0;
    findSubsetSum(set, n, target, current, index + 1, currentSum);
}

void findSubsets(int set[], int n, int target) {
    int current[n];
    findSubsetSum(set, n, target, current, 0, 0);
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    int set[n];
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    findSubsets(set, n, target);

    if (!foundSolution) {
        cout << "No subset found with the target sum." << endl;
    }

    return 0;
}
