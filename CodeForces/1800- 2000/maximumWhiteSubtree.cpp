#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], dp[200007], res[200007];
vector<ll> adj[200007];

void dfs(ll x, ll p) {
    ll ans = a[x];
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] == p) continue;
        dfs(adj[x][i], x);
        ans += max(0ll, dp[adj[x][i]]);
    }

    dp[x] = ans;
    return;
}

void dfs2(ll x, ll p) {
    res[x] = dp[x];
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] == p) continue;
        dp[x] -= max(0ll, dp[adj[x][i]]);
        dp[adj[x][i]] += max(0ll, dp[x]);

        dfs2(adj[x][i], x);

        dp[adj[x][i]] -= max(0ll, dp[x]);
        dp[x] += max(0ll, dp[adj[x][i]]);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(!a[i]) a[i] = -1;
    }

    for(ll i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);
    dfs2(0, -1);

    for(ll i = 0; i < n; ++i) cout << res[i] << ' ';
    return 0;
}