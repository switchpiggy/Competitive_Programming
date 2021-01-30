#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll n, m, a[20][10007], dp[(1ll << 17)], used[(1ll << 17)], adj[20], g[20];

bool go(ll mask) {
    if(dp[mask] != -1) return dp[mask];
    dp[mask] = 0;
    used[mask] = 0;
    for(ll i = 0; i < n; ++i) {
        if(!(mask & (1 << i))) continue;
        if(!(go(mask ^ (1 << i)))) continue;
        if(!(adj[i] & used[mask ^ (1 << i)])) continue;

        dp[mask] = 1;
        used[mask] |= (1 << i);
    }

    return dp[mask];
}

bool check(ll k) {
    m0(adj);
    m0(g);
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            //if(i == j) continue;
            bool ok = 1;
            for(ll l = 0; l < m - 1; ++l) {
                if(abs(a[i][l] - a[j][l + 1]) < k) {
                    ok = 0;
                    break;
                }
            }

            if(ok) g[j] |= (1 << i);
        }
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            bool ok = 1;
            for(ll l = 0; l < m; ++l) {
                if(abs(a[i][l] - a[j][l]) < k) {
                    ok = 0;
                    break;
                }
            }

            if(ok) {
                adj[i] |= (1 << j);
                adj[j] |= (1 << i);
            }
        }
    }

    for(ll i = 0; i < n; ++i) {
        memset(dp, -1, sizeof(dp));
        for(ll j = 0; j < n; ++j) {
            dp[(1 << j)] = (i == j);
            used[(1 << j)] = (1 << j);
        }

        go((1 << n) - 1);
        for(ll j = 0; j < n; ++j) {
            if((g[i] & (1 << j)) && (used[(1 << n) - 1] & (1 << j))) return 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> a[i][j];
    }

    /*if(n == 1) {
        ll mins = LLONG_MAX;
        for(ll i = 0; i < m - 1; ++i) mins = min(mins, abs(a[0][i + 1] - a[0][i]));
        cout << mins << '\n';
        return 0;
    }*/

    ll l = 0, r = 1e9, ans = 0;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid;
    }

    cout << ans << '\n';
    return 0;
}