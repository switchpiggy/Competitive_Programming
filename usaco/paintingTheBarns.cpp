#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b, color[200007];
vector<ll> adj[200007];

void no() {
    printf("NO\n");
    exit(0);
}

void dfs(ll x, ll c) {
    color[x] = c;

    for(ll i = 0; i < adj[x].size(); ++i) {
        if(color[adj[x][i]]) {
            if(color[adj[x][i]] == color[x]) no();
        } else dfs(x, 3 - c);
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(ll i = 1; i <= n; ++i) {
        if(!color[i]) dfs(i, 1);
    }

    printf("YES\n");

    return 0;
}