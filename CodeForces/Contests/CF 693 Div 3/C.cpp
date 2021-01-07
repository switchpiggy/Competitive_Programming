#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll t, n, a[200007], dp[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            dp[i] = a[i];
        }

        for(ll i = 0; i < n; ++i) {
            if(i + a[i] < n) dp[i + a[i]] = max(dp[i + a[i]], dp[i] + a[i + a[i]]);
        }

        ll ans = 0;
        for(ll i = 0; i < n; ++i) ans = max(ans, dp[i]);

        cout << ans << '\n';
    }

    return 0;
}