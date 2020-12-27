#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, u, v, w, sz[100007], dp1[100007], dp2[100007];
vector<pair<ll, ll>> adj[100007];

bool lk(ll x) {
    string s = to_string(x);
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] != '4' && s[i] != '7') return 0;
    }

    return 1;
}

void subtree_size(ll x, ll par) {
    sz[x] = 1;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i].first == par) continue;
        subtree_size(adj[x][i].first, x);
        sz[x] += sz[adj[x][i].first];
    }

    return;
}

void dfs1(ll x, ll par) {
    dp1[x] = 0;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i].first == par) continue;
        dfs1(adj[x][i].first, x);
        if(lk(adj[x][i].second)) dp1[x] += sz[adj[x][i].first];
        else dp1[x] += dp1[adj[x][i].first];
    }

    return;
}

void dfs2(ll x, ll par) {
    if(x == 1) dp2[x] = 0;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i].first == par) continue;
        if(lk(adj[x][i].second)) dp2[adj[x][i].first] = sz[1] - sz[adj[x][i].first];
        else dp2[adj[x][i].first] = dp2[x] + dp1[x] - dp1[adj[x][i].first];
        dfs2(adj[x][i].first, x);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    subtree_size(1, -1);
    dfs1(1, -1);
    dfs2(1, -1);

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ans += 2 * dp1[i] * dp2[i] + max(0ll, dp1[i] * (dp1[i] - 1)) + max(0ll, dp2[i] * (dp2[i] - 1));
    }

    cout << ans << '\n';
    return 0;
}