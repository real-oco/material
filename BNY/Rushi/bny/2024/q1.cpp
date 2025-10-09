// Number of unique subarrays containing exactly k odd
// numbers.

#include <bits/stdc++.h>
using namespace std;
unordered_set<string> res;
int helper(vector<int> &nums, int k)
{
    unordered_set<string> st;
    for (int i = 0; i < nums.size(); i++)
    {
        string temp = "";
        int oddCnt = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] % 2 == 1)
            {
                oddCnt++;
            }
            temp += (to_string(nums[j]));
            if (oddCnt == k)
            {
                st.insert(temp);
            }
            else if (oddCnt > k)
            {
                break;
            }
        }
    }
    res=st;
    return st.size();
}
int main()
{
    vector<int> nums = {1, 3, 2, 4, 5};
    int k = 2;
    int ans = helper(nums, k);
    cout <<"Number of SubArrays are : "<< ans << endl;
    cout<<"All the possible subarrays are :"<<endl<<endl;
    for(auto it : res) cout<<it<<endl<<endl;
    return 0;
}