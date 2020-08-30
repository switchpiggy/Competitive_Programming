#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[107], dp[107][100007];

ll c(ll child, ll candies) {
    cout << child << ' ' << candies << endl;
    if(dp[child][candies] != -1) return dp[child][candies];

    if(child == 1) {
        dp[child][candies] = 1;
        return 1;
    }
    if(candies == 0) {
        dp[child][candies] = 1;
        return 1;
    }

    //if(dp[child][candies] != -1) return dp[child][candies];

    ll ans = 0;
    for(ll i = 0; i <= a[child] && i <= candies; ++i) {
        ans += c(child - 1, candies - i);
    }

    dp[child][candies] = ans;
    return ans;
}

int main() {
    for(ll i = 0; i <= 106; ++i) {
        for(ll j = 0; j <= 100006; ++j) dp[i][j] = -1;
    }

    cin >> n >> k;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    c(n, k);

    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j <= k; ++j) cout << dp[i][j] << ' ';
        cout << endl;
    }

    cout << dp[n][k] << endl;
    return 0;
}