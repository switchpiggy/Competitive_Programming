#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[200007], dp[200007];

int main() {
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);

    ll pref = 0;
    for(ll i = 1; i <= n; ++i) {
        pref += a[i];
        dp[i] += pref;
        if(i + m <= n) dp[i + m] += dp[i];
    }

    for(ll i = 1; i <= n; ++i) cout << dp[i] << ' ';
    cout << endl;

    return 0;
}