#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
ll n, t, w, dp[107][207][207];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> t >> w;
        v.push_back({t, w});
    }

    dp[0][0][0] = 1;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j <= 200; ++j) {
            for(ll k = 0; k <= 200; ++k) {
                if(j + v[i].first <= 200) dp[i + 1][j + v[i].first][k] += dp[i][j][k];
                if(k + v[i].second <= 200) dp[i + 1][j][k + v[i].second] += dp[i][j][k];
            }
        }
    }

    //cout << dp[n][5][4] << '\n';
    for(ll j = 0; j <= 200; ++j) {
        bool ok = 0;
        for(ll k = 0; k <= j; ++k) {
            if(dp[n][j][k]) {
                ok = 1;
                break;
            }
        }

        if(ok) {
            cout << j << '\n';
            return 0;
        }
    }
}