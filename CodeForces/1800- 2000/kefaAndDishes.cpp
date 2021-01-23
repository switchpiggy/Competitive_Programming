#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
ll n, m, k, dp[1000007][20], a[20], adj[20][20];
vector<ll> pc[20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));

    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 0; i < k; ++i) {
        ll x, y, c;
        cin >> x >> y >> c;
        adj[x][y] = c;
    }

    for(ll i = 0; i <= (1ll << (n + 1)); ++i) {
        pc[__builtin_popcount(i)].push_back(i);
    }

    for(ll i = 1; i <= n; ++i) {
        dp[(1ll << i)][i] = a[i];
    }

    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j < sz(pc[i]); ++j) {
            ll mask = pc[i][j];
            for(ll l = 1; l <= n; ++l) {
                if(dp[mask][l] == -1) continue;
                if(!(mask & (1ll << l))) continue;
                for(ll q = 1; q <= n; ++q) {
                    if(mask & (1ll << q)) continue;
                    dp[mask + (1ll << q)][q] = max(dp[mask + (1ll << q)][q], dp[mask][l] + a[q] + adj[l][q]); 
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < sz(pc[m]); ++i) {
        for(ll j = 0; j <= n; ++j) ans = max(ans, dp[pc[m][i]][j]);
    }

    cout << ans << '\n';
    return 0;
}