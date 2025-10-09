#include <bits/stdc++.h>
using namespace std;

int dp[1001][26][2]; // s.length() <= 1000, 26 letters, is_good = 0/1
string s;

int solve(int i, int last_char, bool is_good) {
    if (i == s.length()) {
        return is_good ? 0 : 1e9; // large cost if string is not good
    }

    int &ans = dp[i][last_char][is_good];
    if (ans != -1) return ans;

    ans = INT_MAX;

    // Option 1: Keep last_char, make s[i] equal to last_char
    int cost1 = abs(s[i] - ('a' + last_char));
    ans = min(ans, solve(i + 1, last_char, 1) + cost1);

    // Option 2: If already good, try all characters
    if (is_good) {
        for (int c = 0; c < 26; ++c) {
            int cost2 = abs(s[i] - ('a' + c));
            ans = min(ans, solve(i + 1, c, 0) + cost2);
        }
    }

    return ans;
}

int minOperationsToMakeGood(string input) {
    s = input;
    memset(dp, -1, sizeof(dp));
    int res = INT_MAX;

    // Try all 26 possibilities for the first character
    for (int c = 0; c < 26; ++c) {
        int cost = abs(s[0] - ('a' + c));
        res = min(res, solve(1, c, 0) + cost);
    }

    return res;
}

// Example
int main() {
    string s = "abab";
    cout << minOperationsToMakeGood(s) << endl; // Output: 2
}
