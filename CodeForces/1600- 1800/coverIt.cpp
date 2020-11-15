#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, u, v, c[200007];
vector<ll> adj[200007];

void dfs(ll x, ll cur) {
    c[x] = cur;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(!c[adj[x][i]]) dfs(adj[x][i], 3 - cur);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) {
            adj[i].clear();
            c[i] = 0;
        }

        for(ll i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 1);
        ll res = 0;
        for(ll i = 1; i <= n; ++i) if(c[i] == 2) res++;

        if(res > n/2) {
            cout << n - res << '\n';
            for(ll i = 1; i <= n; ++i) if(c[i] == 1) cout << i << ' ';
        } else {
            cout << res << '\n';
            for(ll i = 1; i <= n; ++i) if(c[i] == 2) cout << i << ' ';
        }

        cout << '\n';
    }

    return 0;
}