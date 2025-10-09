#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int j = mid + 1;
    int i = low;
    while (i <= mid && j <= high)
    {
        if (nums[i] < nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(nums[j]);
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}
void mergesort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergesort(nums, low, mid);
    mergesort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
int main()
{
    vector<int> nums = {1, 0, 2, 9, 3, 8, 4, 7, 5, 6};
    mergesort(nums, 0, nums.size() - 1);
    for (auto it : nums)
        cout << it << " ";
    return 0;
}