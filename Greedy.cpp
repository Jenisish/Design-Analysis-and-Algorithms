#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
};

bool cmp(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

double knapsack_greedy(int W, Item arr[], int n, int consider[], int consider_weight[], int consider_value[]) {
    sort(arr, arr+n, cmp);
    double res = 0.0;
    int i;
    
    for(i=0; i<n; i++) {
        if(W >= arr[i].weight) {
            res += arr[i].value;
            W -= arr[i].weight;
            consider[i] = 1;
            consider_weight[i] = arr[i].weight;
            consider_value[i] = arr[i].value;
        }
        else {
            break;
        }
    }
    if(i < n) {
        consider[i] = (W > 0) ? 1 : 0;
        consider_weight[i] = (W > 0) ? W : 0;
        consider_value[i] = (W > 0) ? (arr[i].value * ((double) W / arr[i].weight)) : 0;
        res += arr[i].value * ((double) W / arr[i].weight);
    }
    return res;
}

int main() {
    int n, W;

    cout<<"Enter the number of items: "<<endl;
    cin>>n;
    
    Item arr[n];
    cout<<"Enter the weight of each item: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i].weight;
    }
    cout<<"Enter the value of each item: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i].value;
    }
    cout <<"Enter the maximum capacity of knapsack: ";
    cin>>W;
    
    int consider[n] ,consider_weight[n], consider_value[n] ;
    consider[n]=0;
    consider_weight[n]=0;
    consider_value[n]=0;
    double max_val = knapsack_greedy(W, arr, n, consider, consider_weight, consider_value);
    
    cout<<"The maximum value that can be obtained is: "<<max_val<<endl;
    cout<<"Items considered: ";
    for(int i=0; i<n; i++) {
        cout<<consider[i]<<" ";
    }
    cout<<endl;
    cout<<"Weight and value of considered items: "<<endl;
    for(int i=0; i<n; i++) {
        cout<<"Item "<<i+1<<": "<<consider_weight[i]<<" "<<consider_value[i]<<endl;
    }
    
    return 0;
}