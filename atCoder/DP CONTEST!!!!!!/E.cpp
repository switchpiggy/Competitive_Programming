#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, w;
pair<ll, ll> val[107];
ll dp[100007];

int main() {
    cin >> n >> w;

    memset(dp, 1000000007, sizeof(dp));
    for(ll i = 0; i < n; ++i) {
        cin >> val[i].first >> val[i].second;
    }

    ll cur = 0;

    dp[0] = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = cur; j >= 0; --j) {
            dp[j + val[i].second] = min(dp[j + val[i].second], dp[j] + val[i].first);
        }
        cur += val[i].second;
    }

    ll ans = cur;
    //cout << dp[ans] << endl;
    while(dp[ans] > w) {
        ans--;
    }

    cout << ans << endl;
    return 0;
}