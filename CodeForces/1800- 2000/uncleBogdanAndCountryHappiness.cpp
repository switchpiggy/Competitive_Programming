#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, p[100007], h[100007], sz[100007], a[100007];
vector<ll> adj[100007];
bool ok = 1;

void dfs(ll x, ll par) {
    sz[x] = 0;
    a[x] = p[x];
    ll sum = 0;

    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] == par) continue;
        dfs(adj[x][i], x);
        a[x] += a[adj[x][i]];
        sum += sz[adj[x][i]];
    }

    sz[x] = (a[x] + h[x])/2;
    if(!(0 <= sz[x] && sz[x] <= a[x] && sz[x] >= sum && (a[x] + h[x])%2 == 0)) ok = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        ok = 1;
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) {
            adj[i].clear();
            cin >> p[i];
        }

        for(ll i = 1; i <= n; ++i) cin >> h[i];

        for(ll i = 0; i < n - 1; ++i) {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        dfs(1, -1);
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}