#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, c, val[1007], dp[2][1007];
vector<pair<ll, ll>> e;

void fileIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO("time");

    cin >> n >> m >> c;
    for(ll i = 1; i <= n; ++i) cin >> val[i];
    for(ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        e.push_back({x, y});
    }

    memset(dp, -1, sizeof(dp));
    dp[0][1] = 0;

    ll ans = 0;
    for(ll i = 1; i <= 1000; ++i) {
        ll cur = i%2;
        memset(dp[cur], -1, sizeof(dp[cur]));

        for(pair<ll, ll> edge : e) {
            ll a = edge.first, b = edge.second;
            if(dp[1 - cur][a] != -1) {
                dp[cur][b] = max(dp[cur][b], dp[1 - cur][a] + val[b]);
            }
        }

        ans = max(ans, dp[cur][1] - c * i * i);
        //cout << dp[cur][1] << '\n';
    }    

    cout << ans << '\n';
    return 0;
}