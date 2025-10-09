#include <bits/stdc++.h>
using namespace std;

int maxScoreSum(vector<int>& scores, int teamSize, int k) {
    int sum = 0;

    deque<int> dq(scores.begin(), scores.end());

    while (teamSize--) {
        int n = dq.size();

        // Extract first k and last k candidates
        int leftMax = -1, rightMax = -1;
        int leftIndex = -1, rightIndex = -1;

        for (int i = 0; i < min(k, n); i++) {
            if (dq[i] > leftMax || (dq[i] == leftMax && leftIndex == -1)) {
                leftMax = dq[i];
                leftIndex = i;
            }
        }

        for (int i = 0; i < min(k, n); i++) {
            int j = n - 1 - i;
            if (dq[j] > rightMax || (dq[j] == rightMax && rightIndex == -1)) {
                rightMax = dq[j];
                rightIndex = j;
            }
        }

        // Decide which one to pick (priority: max score, then lower index)
        int pickIndex;
        if (leftMax > rightMax) {
            pickIndex = leftIndex;
        } else if (rightMax > leftMax) {
            pickIndex = rightIndex;
        } else {
            pickIndex = min(leftIndex, rightIndex); // tie-breaking by index
        }

        sum += dq[pickIndex];
        dq.erase(dq.begin() + pickIndex);  // remove selected score
    }

    return sum;
}

int main() {
    vector<int> scores = {10, 20, 10, 15, 5, 30, 20};
    int teamSize = 2, k = 3;
    cout << maxScoreSum(scores, teamSize, k) << endl; // Output: 50
    return 0;
}
