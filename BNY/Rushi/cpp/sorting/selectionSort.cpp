#include <bits/stdc++.h>
using namespace std;
void selection(int arr[],int n){
for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}
int main(){
    int arr[10]={0,9,7,5,4,3,1,2,8,6};
    selection(arr,10);
    for(auto it : arr) cout<<it<<" ";
    return 0;
}