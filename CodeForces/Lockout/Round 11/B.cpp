#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, a[100007], dp[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    dp[0] = 1;
    for(ll i = 1; i < n; ++i) dp[i] = 2;
    for(ll i = 2; i < n; ++i) {
        if(a[i] == a[i - 1] + a[i - 2]) dp[i] = max(dp[i], dp[i - 1] + 1);
    }

    ll ans = 1;
    for(ll i = 1; i < n; ++i) {
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
    return 0;
}