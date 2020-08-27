#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, u, v, h[100007], d[100007];
vector<ll> adj[100007];

ll dfs(ll cur, ll prev) {
    if(adj[cur].size() == 1 && adj[cur][0] == prev) {
        h[cur] = 0;
        return 0;
    }
    ll maxn = 0;

    for(ll i = 0; i < adj[cur].size(); ++i) {
        if(adj[cur][i] == prev) continue;
        maxn = max(maxn, dfs(adj[cur][i], cur));
    }
    maxn++;

    h[cur] = maxn;

    return maxn;
}

void dfs2(ll cur, ll prev, ll cnt) {
    d[cur] = cnt;
    for(ll i = 0; i < adj[cur].size(); ++i) {
        if(adj[cur][i] == prev) continue;
        dfs2(adj[cur][i], cur, cnt + 1);
    }
    return;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n - 1; ++i) {
        scanf("%lld %lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    dfs2(1, -1, 0);

    for(ll i = 1; i <= n; ++i) printf("%lld ", h[i]);
    printf("\n");
    for(ll i = 1; i <= n; ++i) printf("%lld ", d[i]);

    return 0;
}