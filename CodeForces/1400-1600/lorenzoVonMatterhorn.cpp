#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, u, v, w, t;
map<ll, ll> adj; //weight of edge from i to parent -> adj[i];

ll lca(ll u, ll v, ll w) {
    ll res = 0;
    while(u != v) {
        if(u > v) {
            res += adj[u];
            adj[u] += w;
            u /= 2;
        } else {
            res += adj[v];
            adj[v] += w;
            v /= 2;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    while(q--) {
        cin >> t;
        if(t == 1) {
            cin >> u >> v >> w;
            lca(u, v, w);
        } else {
            cin >> u >> v;
            cout << lca(u, v, 0) << '\n';
        }
    }

    return 0;
}