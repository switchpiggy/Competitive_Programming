#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 998244353LL;
ll n, m, k, dp[2007][2007];

ll fastPow(ll x) {
    ll ans = 1, cur = x, w = MOD - 2;
    while(w) {
        if(w%2) {
            ans *= cur;
            ans %= MOD;
        }
        w /= 2;
        cur *= cur;
        cur %= MOD;
    }

    return ans%MOD;
}

ll choose(ll w, ll r) {
    ll ans = 1;
    for(ll i = 1; i <= r; ++i) {
        ans *= w - r + i;
        ans %= MOD;
    }

    ll d = 1;
    for(ll i = 1; i <= r; ++i) {
        d *= i;
        d %= MOD;
    }
  
    ans *= fastPow(d);
    ans %= MOD;

    return ans%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    //cout << choose(3, 3) << '\n';

    ll ans = m;
    for(ll i = 0; i < k; ++i) {
        ans *= m - 1;
        ans %= MOD;
    }

    ans *= choose(n - 1, k);
    ans %= MOD;

    cout << ans << '\n';
    return 0;
}