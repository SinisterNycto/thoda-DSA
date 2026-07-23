// Question: https://cses.fi/problemset/task/1628

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long x;

    cin >> n >> x;
    vector<long long> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // split the array into two parts
    int n1 = n / 2;
    int n2 = n - n1;

    // first half

    vector<long long> sumsA(1LL << n1); // no. of subsets = 2^n1

    for(int mask = 0; mask < (1 << n1); mask++){
        long long sum = 0;
        // check which bits are set in mask
        for(int i = 0; i < n1; i++){
            if(mask & (1 << i)){
                sum += arr[i];
            }
        }

        sumsA[mask] = sum;
    }

    // second half

    vector<long long> sumsB(1LL << n2); // no. of subsets = 2^n2

    for(int mask = 0; mask < (1 << n2); mask++){
        long long sum = 0;
        // check which bits are set in mask
        for(int i = 0; i < n2; i++){
            if(mask & (1 << i)){
                sum += arr[i + n1];
            }
        }

        sumsB[mask] = sum;
    }

    sort(sumsB.begin(), sumsB.end());
    long long cnt = 0;
    // iterate on subsA and apply Binary Search on subsB
    for(long long s: sumsA){
        long long need = x - s; // remaining sum
        // low and high are indices
        auto low = lower_bound(sumsB.begin(), sumsB.end(), need);
        auto high = upper_bound(sumsB.begin(), sumsB.end(), need);

        cnt += (high - low);
    }

    cout << cnt << endl;

    return 0;
}
