#include <bits/stdc++.h>
using namespace std;

int frogJumpK(vector<int> &heights, int idx, int k, vector<int> &dp) {
    dp[0] = 0;
    
    for(int i = 1; i < heights.size(); i++){
        int minSteps = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
               int jumps = dp[i - j] + abs(heights[i] - heights[i - j]); 
               minSteps = min(minSteps, jumps);
            }
        }
        dp[i] = minSteps;
    }
    
    return dp[idx];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];

    vector<int> dp(n, 0);

    cout << frogJumpK(heights, n - 1, k, dp) << endl;

    return 0;
}
