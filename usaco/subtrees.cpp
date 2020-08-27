#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, u, v, res[100007];
vector<ll> adj[100007];

ll dfs(ll cur, ll prev) {
    if(adj[cur].size() == 1 && adj[cur][0] == prev) return 1;

    ll ans = 1;
    for(ll i = 0; i < adj[cur].size(); ++i) {
        ans += dfs(adj[cur][i], cur);
    }

    res[cur] = ans; 
    return ans;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n - 1; ++i) {
        scanf("%lld %lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll temp = dfs(1);

    for(ll i = 1; i <= n; ++i) printf("%lld ", res[i]);

    return 0;
}