#include <bits/stdc++.h>
using namespace std;

int frogJumpK(vector<int> &heights, int idx, int k, vector<int> &dp) {
    if (idx == 0) return 0;

    if (dp[idx] != -1) return dp[idx];

    int minSteps = INT_MAX;

    for (int jump = 1; jump <= k; jump++) {
        if (idx - jump >= 0) {
            int cost = frogJumpK(heights, idx - jump, k, dp) + abs(heights[idx] - heights[idx - jump]);
            minSteps = min(minSteps, cost);
        }
    }

    return dp[idx] = minSteps;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];

    vector<int> dp(n, -1);

    cout << frogJumpK(heights, n - 1, k, dp) << endl;

    return 0;
}
