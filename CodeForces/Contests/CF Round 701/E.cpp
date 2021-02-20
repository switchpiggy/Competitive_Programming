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
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll t, n, p[200007], d[200007], dp[200007], a[200007], maxn[200007], minn[200007], maxn2[200007], maxn3[200007];
vector<ll> adj[200007], g[200007];
ll MAX_D = 0;

void dfs1(ll x) {
    MAX_D = max(MAX_D, d[x]);
    g[d[x]].push_back(x);
    maxn[d[x]] = max(maxn[d[x]], a[x]);
    minn[d[x]] = min(minn[d[x]], a[x]);

    for(ll i : adj[x]) {
        if(i == p[x]) continue;
        d[i] = d[x] + 1;
        p[i] = x;
        dfs1(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        MAX_D = 0;
        cin >> n;
        for(ll i = 1; i <= n; ++i) g[i].clear(), adj[i].clear(), maxn[i] = maxn2[i] = LLONG_MIN, minn[i] = LLONG_MAX, maxn3[i] = LLONG_MIN, dp[i] = 0;

        for(ll i = 2; i <= n; ++i) {
            ll x;
            cin >> x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }

        a[1] = d[1] = p[1] = 0;
        for(ll i = 2; i <= n; ++i) cin >> a[i];
        dfs1(1);

        dp[1] = 0;
        //cout << MAX_D << '\n';
        for(ll i = 1; i <= MAX_D; ++i) {
            //cout << i << '\n';
            //for(ll j : g[i]) cout << dp[p[j]] << ' ';
            //cout << '\n';
            for(ll j : g[i]) {
                maxn2[i] = max(maxn2[i], dp[p[j]] + a[j]);
                maxn3[i] = max(maxn3[i], dp[p[j]] - a[j]);
            }

            for(ll j : g[i]) {
                dp[j] = max(max(dp[p[j]] + maxn[i] - a[j], dp[p[j]] + a[j] - minn[i]), max(maxn2[i] - a[j], maxn3[i] + a[j]));
            }
        }

        ll ans = 0;
        //cout << dp[1] << '\n';
        for(ll i = 1; i <= n; ++i) ans = max(ans, dp[i]);
        //cout << '\n';
        //for(ll i = 1; i <= n; ++i) cout << p[i] << ' ';
        //for(ll i = 1; i <= 3; ++i) cout << maxn[i][0] << ' ' << minn[i][0] << '\n';
        cout << ans << '\n';
    }
}