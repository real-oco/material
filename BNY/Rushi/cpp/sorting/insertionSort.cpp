#include <bits/stdc++.h>
using namespace std;
void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[10] = {1, 3, 4, 5, 7, 9, 0, 2, 6, 8};
    insertion(arr, 10);
    for (auto it : arr)
        cout << it << " ";
}

// For an array of size n:

// Loop from i = 1 to n-1:

// Store the current element in a variable key.

// Set j = i - 1.

// While j >= 0 and arr[j] > key, shift arr[j] to arr[j+1].

// Place key at arr[j+1].
