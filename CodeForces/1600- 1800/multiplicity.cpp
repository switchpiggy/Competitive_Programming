#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], dp[1000007];
const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    dp[0] = 1;
    for(ll i = 0; i < n; ++i) {
        for(ll j = sqrt(a[i]); j >= 1; --j) {
            if(a[i]%j == 0) {
                if(a[i]/j != j) {
                    dp[a[i]/j] += dp[a[i]/j - 1];
                    dp[a[i]/j] %= MOD;
                }

                dp[j] += dp[j - 1];
                dp[j] %= MOD;
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ans = (ans + dp[i])%MOD;
        //cout << dp[i] << ' ';
    }

    cout << ans << '\n';
    return 0;
}