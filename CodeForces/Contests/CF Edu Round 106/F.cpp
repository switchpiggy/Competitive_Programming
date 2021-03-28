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
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, k, x, y, dp[5007][5007];
vector<ll> adj[200007];

ll dfs(ll x, ll p = -1) {
    dp[x][0] = 1;
    ll cur = 0;

    for(ll i : adj[x]) {
        if(i == p) continue;
        ll cur2 = dfs(i, x);
        vector<ll> dpt(max(cur, cur2 + 1) + 1);
        for(ll j = 0; j <= cur; ++j) {
            for(ll l = 0; l <= cur2; ++l) {
                if(j + l + 1 <= k) {
                    (dpt[max(j, l + 1)] += (dp[x][j] * dp[i][l])%MOD) %= MOD;
                }

                if(j <= k && l <= k) {
                    (dpt[j] += (dp[x][j] * dp[i][l])%MOD) %= MOD;
                }
            }
        }

        cur = max(cur, cur2 + 1);
        for(ll j = 0; j <= cur; ++j) dp[x][j] = dpt[j];
    }

    return cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    ll ans = 0;
    for(ll i = 0; i <= k; ++i) (ans += dp[1][i]) %= MOD;

    cout << ans << '\n';
    return 0;
}