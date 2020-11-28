#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dist[300007];
vector<ll> adj[300007];

void bfs(ll x, ll p, ll d) {
    dist[x] = d;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] == p) continue;
        bfs(adj[x][i], x, d + 1);
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
    ll maxn = 1;
    for(ll i = 1; i <= n; ++i) {
        if(dist[i] > dist[maxn]) maxn = i;
    }

    memset(dist, 0, sizeof(dist));
    bfs(maxn, -1, 0);

    maxn = 0;
    for(ll i = 1; i <= n; ++i) maxn = max(maxn, dist[i]);

    cout << maxn * 3 << '\n';
    return 0;
}