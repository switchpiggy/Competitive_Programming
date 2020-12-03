#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, t;
vector<pair<ll, ll>> adj[5007];
vector<ll> cur;
vector<ll> ans;

void dfs(ll x, ll tm) {
    if(tm > t) return;
    if(x == n) {
        if((ll)cur.size() > (ll)ans.size()) ans = cur;
        return;
    }

    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        cur.push_back(adj[x][i].first);
        dfs(adj[x][i].first, tm + adj[x][i].second);
        cur.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    for(ll i = 0; i < m; ++i) {
        ll u, v, q;
        cin >> u >> v >> q;
        adj[u].push_back({v, q});
    }

    cur.push_back(1);
    dfs(1, 0);
    cout << (ll)ans.size() << '\n';
    for(ll i : ans) cout << i << ' ';
    return 0;
}