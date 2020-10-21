#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, x, y, res, deg[200007];
vector<ll> adj[200007];

bool visited[200007];

void dfs(ll x) {
    visited[x] = 1;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(!visited[adj[x][i]]) {
            cout << x << ' ' << adj[x][i] << '\n';
            dfs(adj[x][i]);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll res = 1;
    for(ll i = 1; i <= n; ++i) {
        deg[i] = (ll)adj[i].size();
        if(deg[i] > deg[res]) res = i;
    }

    visited[res] = 1;
    for(ll i = 0; i < (ll)adj[res].size(); ++i) {
        cout << res << ' ' << adj[res][i] << '\n';
        visited[adj[res][i]] = 1;
    }

    for(ll i = 0; i < (ll)adj[res].size(); ++i) dfs(adj[res][i]);

    return 0;
}