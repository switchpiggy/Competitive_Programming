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
ll n, a[200007], elt[400007], in[200007], out[200007], p[200007], cur, dp[200007], ans;
set<pair<ll, ll>> e;
map<ll, vector<ll>> v, t;
vector<ll> adj[200007];

void tour(ll x, ll par) {
    p[x] = par;
    elt[++cur] = x;
    in[x] = cur;

    for(ll i : adj[x]) {
        if(i == p[x]) continue;
        tour(i, x);
        elt[++cur] = x;
    }

    out[x] = cur;
}

void init(ll x) {
    ll cnt = 0;
    for(ll i : adj[x]) {
        if(i == p[x]) continue;
        ll res = upper_bound(all(t[a[x]]), out[i]) - lower_bound(all(t[a[x]]), in[i]);
        if(res > 0) e.insert({x, i});
        // init(i);
        cnt += res;
    }

    if(sz(t[a[x]]) - 1 - cnt > 0) e.insert({x, p[x]});
}

ll dfs(ll x) {
    for(ll i : adj[x]) {
        if(i == p[x]) continue;
        dp[x] += dfs(i);
    }

    return dp[x] + e.count({x, p[x]});
}

void reroot(ll x) {
    if(dp[x] == sz(e)) ans++;
    for(ll i : adj[x]) {
        if(i == p[x]) continue;
        dp[x] -= dp[i];
        dp[x] -= e.count({i, x});
        dp[i] += dp[x];
        dp[i] += e.count({x, i});

        reroot(i);

        dp[i] -= e.count({x, i});
        dp[i] -= dp[x];
        dp[x] += dp[i];
        dp[x] += e.count({i, x});
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(ll i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    tour(1, -1);
    for(ll i = 1; i <= n; ++i) v[a[i]].push_back(i);

    for(auto i : v) {
        if(sz(i.second) == 1) continue;

        for(ll j : i.second) t[i.first].push_back(in[j]);
        sort(all(t[i.first]));

        for(ll j : i.second) {
            init(j);
        }
    }

    dfs(1);
    reroot(1);

    cout << ans << '\n';
    return 0;
}