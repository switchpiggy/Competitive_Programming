#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, p[4007], mx[4007], dp[4007][4007];
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        //memset(mx, 0, sizeof(mx));
        //memset(dp, 0, sizeof(dp));
        //vector<ll> v;
        v.clear();
        for(ll i = 1; i <= 2 * n; ++i) {
            cin >> p[i];
            mx[i] = 0;
            mx[i] = max(mx[i - 1], p[i]);
            //cout << p[i] << ' ' << mx[i] << ' ';
        }

        ll prev = 2 * n + 1;
        for(ll i = 2 * n; i >= 1; --i) {
            if(p[i] == mx[i]) {
                v.push_back(prev - i);
                prev = i;
            }
        }

        for(ll i = 0; i <= (ll)v.size(); ++i) {
            for(ll j = 0; j <= n; ++j) dp[i][j] = 0;
        }

        dp[0][0] = 1;
        for(ll i = 0; i < (ll)v.size(); ++i) {
            for(ll j = 0; j <= n; ++j) {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j + v[i]] += dp[i][j];
            }
        }

        if(dp[(ll)v.size()][n]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}