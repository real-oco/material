#include <bits/stdc++.h>
using namespace std;

// 🔹 Helper function to compute discounted price for a product
int helper(vector<string>& curr, unordered_map<string, pair<int, int>>& mpp) {
    int originalPrice = stoi(curr[0]);
    int minCost = originalPrice;

    for (int i = 1; i < curr.size(); i++) {
        string tag = curr[i];

        if (tag == "EMPTY" || mpp.find(tag) == mpp.end()) continue;
   
        int type;int x;
        auto it  = mpp[tag];
        type=it.first;
        x=it.second;
        int discountedPrice = originalPrice;

        if (type == 1) {
            discountedPrice = x;
        } else if (type == 2) {
            discountedPrice = originalPrice - (originalPrice * x) / 100;
        } else if (type == 3) {
            discountedPrice = originalPrice - x;
        }

        minCost = min(minCost, discountedPrice);
    }

    return minCost;
}

// 🔸 Main function
int getMinimumTotalCost(vector<vector<string>>& products, vector<vector<string>>& discounts) {
    unordered_map<string, pair<int, int>> mpp;

    for (auto& d : discounts) {
        string tag = d[0];
        int type = stoi(d[1]);
        int val = stoi(d[2]);
        mpp[tag] = {type, val};
    }

    int totalCost = 0;
    for (auto& product : products) {
        totalCost += helper(product, mpp);
    }

    return totalCost;
}

// 🔹 Driver code
int main() {
    // Test Case 1
    vector<vector<string>> products = {
        {"50", "d1", "d2"},
        {"30", "d1", "EMPTY", "d3"},
        {"100", "d2", "d3"}
    };

    vector<vector<string>> discounts = {
        {"d1", "1", "25"},
        {"d2", "2", "5"},
        {"d3", "3", "10"}
    };

    int ans = getMinimumTotalCost(products, discounts);
    cout << "Minimum Total Cost: " << ans << endl << endl;  // Expected: 135

    // Test Case 2
    vector<vector<string>> products2 = {
        {"200", "d5", "EMPTY"},
        {"100", "d4"}
    };

    vector<vector<string>> discounts2 = {
        {"d4", "2", "20"},
        {"d5", "3", "50"}
    };

    ans = getMinimumTotalCost(products2, discounts2);
    cout << "Minimum Total Cost (Test 2): " << ans << endl;  // Expected: 230

    return 0;
}
