#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<vector<int>> mat;
int dp[101][101][11]; // adjust size as needed

int dfs(int i, int j, int count) {
    if (i >= N || j >= M || count > K) return INT_MIN;

    // Base case: reached destination
    if (i == N - 1 && j == M - 1) {
        return (count <= K) ? mat[i][j] : INT_MIN;
    }

    if (dp[i][j][count] != -1) return dp[i][j][count];

    int right = INT_MIN, down = INT_MIN;

    // Move right in same row
    right = dfs(i, j + 1, count + 1);

    // Move down to next row, count resets to 1
    down = dfs(i + 1, j, 1);

    int best = mat[i][j] + max(right, down);

    return dp[i][j][count] = best;
}

int getMaxPathSum(vector<vector<int>>& matrix, int k) {
    mat = matrix;
    N = mat.size();
    M = mat[0].size();
    K = k;

    memset(dp, -1, sizeof(dp));

    return dfs(0, 0, 1); // starting from (0,0) with 1 element in row used
}

int main() {
    vector<vector<int>> mat1 = {
        {2, 10, 8},
        {8, 8, 8},
        {0, 1, 0}
    };
    int K1 = 2;
    cout << "Output 1: " << getMaxPathSum(mat1, K1) << endl; // 28

    vector<vector<int>> mat2 = {
        {0, 0, 4},
        {0, 5, 0},
        {3, 0, 2}
    };
    int K2 = 1;
    cout << "Output 2: " << getMaxPathSum(mat2, K2) << endl; // 7

    return 0;
}
