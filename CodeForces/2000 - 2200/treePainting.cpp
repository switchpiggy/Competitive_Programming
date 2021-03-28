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
ll n, sz[200007], ans, dp[200007];
vector<ll> adj[200007];

void dfs1(ll x, ll p = -1) {
    sz[x] = 1, dp[x] = 1;
    for(ll i : adj[x]) {
        if(i == p) continue;
        dfs1(i, x);
        sz[x] += sz[i];
        dp[x] += dp[i] + sz[i];
    }
}

void dfs2(ll x, ll p = -1) {
    ans = max(ans, dp[x]);

    for(ll i : adj[x]) {
        if(i == p) continue;
        sz[x] -= sz[i];
        dp[x] -= sz[i] + dp[i];
        sz[i] += sz[x];
        dp[i] += sz[x] + dp[x];
        dfs2(i, x);
        dp[i] -= sz[x] + dp[x];
        sz[i] -= sz[x];
        sz[x] += sz[i];
        dp[x] += sz[i] + dp[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs1(1);
    dfs2(1);

    cout << ans << '\n';
    return 0;
}