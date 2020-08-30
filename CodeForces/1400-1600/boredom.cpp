#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, occ[100007], dp[100007];

int main() {
    cin >> n;

    ll maxn = 0;
    for(ll i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        occ[temp]++;
        maxn = max(temp, maxn);
    }

    dp[1] = occ[1];

    for(ll i = 0; i <= maxn; ++i) {
        dp[i + 2] = max(dp[i + 2], dp[i] + occ[i + 2] * (i + 2));
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }

    //for(ll i = 1; i <= maxn; ++i) cout << occ[i] << ' ';

    cout << dp[maxn] << endl;
    return 0;
}