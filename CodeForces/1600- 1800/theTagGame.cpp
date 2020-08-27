#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> adj[200005];
ll dist[2][200005], n, x;
ll a, b;

void dfs(ll cur, ll prev, ll column) {
    for(ll i = 0; i < adj[cur].size(); ++i) {
        if(adj[cur][i] == prev) continue;
        dist[column][adj[cur][i]] = dist[column][cur] + 1;
        dfs(adj[cur][i], cur, column);
    }
    return;
}

int main() {

    scanf("%lld %lld", &n, &x);
    x--;
    for(ll i = 1; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist[0][0] = 0;
    dist[1][x] = 0;

    dfs(0, -1, 0);
    dfs(x, -1, 1);

    ll ans = 0;

    for(ll i = 0; i < n; ++i) {
        if(dist[1][i] < dist[0][i]) ans = max(ans, dist[0][i]);
    }

    printf("%lld", ans * 2);
}