#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int partition(int arr[], int lb, int ub) 
{
    int pivot = arr[ub];
    int i = lb - 1;

    for (int j = lb; j < ub; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[ub]);

    return i + 1;
}
void quicksort(int arr[], int lb, int ub) 
{
    if (lb < ub) 
    {
        int pivot_index = partition(arr, lb,ub);
        quicksort(arr, lb, pivot_index - 1);
        quicksort(arr, pivot_index + 1, ub);
    }
}
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(NULL)); 
    int n=5000;
    int arr[n];
    cout<<"enter the number of elements : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 5000 + 5000;
    }

    cout << "Unsorted array:" << endl;
    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    cout << "\nSorted array:" << endl;
    printArray(arr, n);
    clock_t start = clock(); 
    
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << timeTaken << "s" << endl;
    return 0; 
}