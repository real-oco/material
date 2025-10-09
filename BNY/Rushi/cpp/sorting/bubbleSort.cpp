#include <bits/stdc++.h>
using namespace std;

void helper(int nums[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

int main() {
    int arr[10] = {2, 1, 3, 6, 4, 5, 7, 9, 8, 0};
    int n = 10;
    
    cout << "Before Sorting:" << endl;
    for (auto it : arr) cout << it << " ";
    cout << endl;

    helper(arr, n);

    cout << "After Sorting:" << endl;
    for (auto it : arr) cout << it << " ";
    cout << endl;

    return 0;
}

// Bubble Sort works by repeatedly swapping adjacent elements if they are in the wrong order.
// In each pass, the largest element "bubbles up" to its correct position at the end.
// Therefore, we need (n - 1) passes to completely sort the array.
//
// Optimization:
// We can add a boolean flag `swapped` to check if any swapping was done in the current pass.
// - If no swapping happened, it means the array is already sorted, and we can break early.
// - This reduces the best-case time complexity to O(n) (when the array is already sorted).
//
// Time Complexity:
// - Best Case: O(n)     [Already sorted]
// - Worst Case: O(n^2)  [Reverse sorted]
// - Space Complexity: O(1) (In-place sorting)
