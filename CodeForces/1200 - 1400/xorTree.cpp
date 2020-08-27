#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, u, v;
ll goal[100007], init[100007];
vector<ll> adj[100007];
vector<ll> ans;

void dfs(ll v, ll prev, ll even, ll odd, ll step) {
    if(step%2 == 0) {
        if((init[v] + even)%2 != goal[v]) {
            even++;
            ans.push_back(v);
        }
    } else {
        if((init[v] + odd)%2 != goal[v]) {
            odd++;
            ans.push_back(v);
        }
    }

    for(ll i = 0; i < adj[v].size(); ++i) {
        if(adj[v][i] != prev) {
            dfs(adj[v][i], v, even, odd, step + 1);
        }
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

    for(ll i = 1; i <= n; ++i) scanf("%lld", &init[i]);
    for(ll i = 1; i <= n; ++i) scanf("%lld", &goal[i]);
    
    dfs(1, 0, 0, 0, 0);

    printf("%lld\n", (ll)ans.size());

    for(ll i = 0; i < ans.size(); ++i) printf("%lld\n", ans[i]);
}