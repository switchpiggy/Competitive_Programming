#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dp[507][507];
string s;

ll topdown(ll l, ll r) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l == r) {
        dp[l][r] = 1;
        return 1;
    }

    if(l > r) {
        dp[l][r] = 0;
        return 0;
    }

    dp[l][r] = 1 + topdown(l + 1, r);
    for(ll i = l + 1; i <= r; ++i) {
        if(s[i] == s[l]) dp[l][r] = min(dp[l][r], topdown(l + 1, i - 1) + topdown(i, r));
    }

    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    memset(dp, -1, sizeof(dp[0][0]) * 507 * 507);
    cout << topdown(0, n - 1) << '\n';
    return 0;
}