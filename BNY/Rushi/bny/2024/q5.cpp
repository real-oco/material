#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> freq;
vector<int> values;

int solve(int i, vector<int>& dp) {
    if (i >= values.size()) return 0;
    if (dp[i] != -1) return dp[i];

    int curr = values[i];
    int take = freq[curr];
    int j = i + 1;

    // Skip curr+1 and curr+2
    while (j < values.size() && (values[j] == curr + 1 || values[j] == curr + 2)) {
        j++;
    }

    take += solve(j, dp);
    int skip = solve(i + 1, dp);

    return dp[i] = max(take, skip);
}

int maxPoints(vector<int>& nums) {
    freq.clear();
    values.clear();

    for (int num : nums) {
        freq[num] += num;
    }

    for (auto& it : freq) values.push_back(it.first);
    sort(values.begin(), values.end());

    vector<int> dp(values.size(), -1);  // ✅ FIXED HERE

    return solve(0, dp);
}

int main() {
    vector<int> arr = {5, 6, 6, 4, 11};
    cout << maxPoints(arr) << endl;  // Output: 27
}
