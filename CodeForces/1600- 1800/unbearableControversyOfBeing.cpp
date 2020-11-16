#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b;
vector<ll> adj[3007];
map<ll, ll> res;

void dfs(ll x, ll p, ll d) {
    if(d == 2) {
        res[x]++;
        return;
    }

    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] != p) {
            dfs(adj[x][i], x, d + 1);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        res.clear();
        dfs(i, -1, 0);
        for(auto j = res.begin(); j != res.end(); ++j) {
            if(j->second >= 2) ans += (j->second * (j->second - 1))/2;
        }
    }

    cout << ans << '\n';
    return 0;
}