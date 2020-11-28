#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dist[300007];
vector<ll> adj[300007];

void bfs(ll x, ll p, ll cur) {
    dist[x] = cur;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] == p) continue;
        bfs(adj[x][i], x, cur + 1);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1, -1, 0);
    vector<ll> ans;
    ll maxn = 0;
    for(ll i = 1; i <= n; ++i) {
        if(dist[i] > maxn) {
            ans.clear();
            maxn = dist[i];
            ans.push_back(i);
        } else if(dist[i] == maxn) ans.push_back(i);
    }

    memset(dist, 0, sizeof(dist));
    bfs(ans[0], -1, 0);

    maxn = 0;
    for(ll i = 1; i <= n; ++i) maxn = max(maxn, dist[i]);

    ll cur = 0;
    for(ll i = 1; i <= n; ++i) {
        if(cur < (ll)ans.size() && ans[cur] == i) {
            cout << maxn + 1 << '\n';
            cur++;
        } else if(dist[i] == maxn) {
            cout << maxn + 1 << '\n';
        } else cout << maxn << '\n';
    }

    return 0;
}