#include <bits/stdc++.h>
using namespace std;

// Partition using first element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low && arr[j] > pivot) j--;

        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); // place pivot in correct position
    return j;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);
        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
    }
}

int main() {
    int arr[10] = {2, 1, 3, 6, 4, 5, 7, 9, 8, 0};
    int n = 10;

    cout << "Before Sorting:" << endl;
    for (auto it : arr) cout << it << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "After Sorting:" << endl;
    for (auto it : arr) cout << it << " ";
    cout << endl;

    return 0;
}
