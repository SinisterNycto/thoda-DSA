// Question: https://cses.fi/problemset/result/18060876/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll dp[20][12][2][2];

ll func(string& str, int idx, int prev, bool tight, bool lz){
    if(idx >= str.length()){
        return 1LL;
    }

    if(dp[idx][prev][tight][lz] != -1){
        return dp[idx][prev][tight][lz];
    }

    int lowerBound = 0;
    int upperBound = (tight == true)  ? str[idx] - '0' : 9;
    ll result = 0;

    for(int dig = lowerBound; dig <= upperBound; dig++){
        // invalid case
        if(!lz && dig == prev){
            continue;
        }

        bool newTight = (tight && (dig == upperBound));
        bool newLz = (lz && (dig == 0));

        result += func(str, idx + 1, dig, newTight, newLz);
    }

    return dp[idx][prev][tight][lz] = result;
}

ll solve(ll a, ll b){
    string R = to_string(b);

    memset(dp, -1, sizeof(dp));
    ll ansR = func(R, 0, 10, true, true);

    if(a == 0){
        return ansR;
    }

    string L = to_string(a - 1);

    memset(dp, -1, sizeof(dp));
    ll ansL = func(L, 0, 10, true, true);

    return ansR - ansL;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;
    
    cout << solve(a, b);

    return 0;
}
