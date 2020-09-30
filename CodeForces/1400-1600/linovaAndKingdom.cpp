#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, u, v, depth[200007], size[200007], ans[200007];
vector<ll> adj[200007];

ll dfs(ll v, ll p) {
    if(p != -1) depth[v] = depth[p] + 1;
    ll res = 1;

    for(ll i = 0; i < (ll)adj[v].size(); ++i) {
        if(adj[v][i] == p) continue;
        res += dfs(adj[v][i], v); 
    }

    size[v] = res;
    ans[v] = size[v] - depth[v];
    return size[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1, -1);

    sort(ans + 1, ans + n + 1, greater<ll>());
    ll res = 0;
    for(ll i = 1; i <= n - k; ++i) res += ans[i];

    cout << res << '\n';
    return 0;
}