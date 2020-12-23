#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, sz[100007];
vector<ll> p;
vector<ll> adj[100007];
vector<ll> res;

const ll MOD = 1e9 + 7;

void dfs(ll x, ll par) {
    sz[x] = 1;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(par == adj[x][i]) continue;
        dfs(adj[x][i], x);
        sz[x] += sz[adj[x][i]];
    }

    res.push_back(sz[x]);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;

        for(ll i = 0; i <= n; ++i) {
            adj[i].clear();
            //sz[i] = 0;
        }
        p.clear();
        res.clear();

        for(ll i = 0; i < n - 1; ++i) {
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cin >> m;
        for(ll i = 0; i < m; ++i) {
            ll a;
            cin >> a;
            p.push_back(a);
        }

        sort(p.begin(), p.end());

        sort(p.begin(), p.end(), greater<ll>());

        dfs(1, -1);
        for(ll i = 0; i < n; ++i) res[i] *= n - res[i];
        sort(res.begin(), res.end(), greater<ll>());
        for(ll i = 0; i < n; ++i) res[i] %= MOD;

        ll ans = 0;
        if(m < n - 1) {
            for(ll i = 0; i < m; ++i) ans = (ans + res[i] * p[i])%MOD;
            for(ll i = m; i < n - 1; ++i) ans = (ans + res[i])%MOD;
        } else {
            ans = res[0];
            for(ll i = 0; i <= m - n + 1; ++i) ans = (ans * p[i])%MOD;
            for(ll i = 1; i < n - 1; ++i) ans = (ans + res[i] * p[m - n + 1 + i])%MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}