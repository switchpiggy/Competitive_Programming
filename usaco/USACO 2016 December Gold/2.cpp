#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, g, dp[1007][1007][2];
vector<pair<ll, ll>> v, t;

ll dist(pair<ll, ll> x, pair<ll, ll> y) {
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> g;
    //v.push_back({0, 0});
    //t.push_back({0, 0});
    for(ll i = 0; i < h; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(ll i = 0; i < g; ++i) {
        ll a, b;
        cin >> a >> b;
        t.push_back({a, b});
    }

    for(ll i = 0; i <= h; ++i) {
        for(ll j = 0; j <= g; ++j) dp[i][j][0] = dp[i][j][1] = LONG_LONG_MAX;
    }

    dp[1][0][0] = 0;
    for(ll i = 0; i <= h; ++i) {
        for(ll j = 0; j <= g; ++j) {
            for(ll k = 0; k < 2; ++k) {
                if(dp[i][j][k] == LONG_LONG_MAX) continue;
                if(k && !j) continue;
                if(!k && !i) continue;
                pair<ll, ll> cur = v[i - 1];
                if(k) cur = t[j - 1];
                if(i < h) dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + dist(cur, v[i]));
                if(j < g) dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + dist(cur, t[j]));
            }
        }
    }

    cout << dp[h][g][0] << '\n';
    return 0;
}