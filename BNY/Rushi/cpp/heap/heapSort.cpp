#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) 
        largest = left;
    if (right < n && arr[right] > arr[largest]) 
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build max-heap
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);

    // Step 2: Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);         // Move max to end
        heapify(arr, i, 0);           // Heapify root on reduced heap
    }
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};

    cout << "Original array:\n";
    for (auto it : nums) cout << it << " ";
    cout << "\n";

    heapSort(nums);

    cout << "Sorted array:\n";
    for (auto it : nums) cout << it << " ";
    cout << "\n";

    return 0;
}

/*
Explanation:
-------------
1. heapify(): Maintains the max-heap property for a subtree rooted at index i.
   - Compares parent with left and right children, swaps if needed, and recurses.

2. heapSort():
   - Builds a max-heap from the array.
   - Repeatedly swaps the root (max element) with the last element, reduces heap size, and heapifies the root.

3. main():
   - Demonstrates heapSort on the array {1, 3, 5, 7, 9, 0, 2, 4, 6, 8}.

Dry Run:
---------
Original array: 1 3 5 7 9 0 2 4 6 8

Step 1: Build max-heap
  After heapify: 9 8 5 7 6 0 2 4 3 1

Step 2: Extract elements
  Swap 9 and 1 -> [1 8 5 7 6 0 2 4 3 9], heapify
  Heap after heapify: 8 7 5 4 6 0 2 1 3 9
  Swap 8 and 3 -> [3 7 5 4 6 0 2 1 8 9], heapify
  Heap after heapify: 7 6 5 4 3 0 2 1 8 9
  Swap 7 and 1 -> [1 6 5 4 3 0 2 7 8 9], heapify
  Heap after heapify: 6 4 5 1 3 0 2 7 8 9
  Swap 6 and 2 -> [2 4 5 1 3 0 6 7 8 9], heapify
  Heap after heapify: 5 4 2 1 3 0 6 7 8 9
  Swap 5 and 0 -> [0 4 2 1 3 5 6 7 8 9], heapify
  Heap after heapify: 4 3 2 1 0 5 6 7 8 9
  Swap 4 and 0 -> [0 3 2 1 4 5 6 7 8 9], heapify
  Heap after heapify: 3 1 2 0 4 5 6 7 8 9
  Swap 3 and 0 -> [0 1 2 3 4 5 6 7 8 9], heapify
  Heap after heapify: 2 1 0 3 4 5 6 7 8 9
  Swap 2 and 0 -> [0 1 2 3 4 5 6 7 8 9], heapify

Sorted array: 0 1 2 3 4 5 6 7 8 9
*/