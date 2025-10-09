#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> & nums,int n,int i){
int left=2*i+1;
int right=2*i+2;
int largest=i;
if(left<n && nums[left]>nums[largest]){
    largest=left;
}
if(right<n && nums[right]>nums[largest]){
    largest=right;
}
if(largest!=i){
    swap(nums[largest],nums[i]);
    heapify(nums,n,largest);
}
}
int main(){
    vector<int> nums={1,3,5,7,9,0,2,4,6,8};
   // will create max-heap of this array first;
   int n=nums.size();
   for(int i=n/2-1;i>=0;i--){
   heapify(nums,n,i);
   }
   for(int i=n-1;i>0;i--){
    swap(nums[0],nums[i]);
    heapify(nums,i,0);
   }

   for(auto it : nums) cout<<it<<" ";
    return 0;
}