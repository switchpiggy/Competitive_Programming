#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
ll n, m, a, b;
vector<ll> adj[257];
bool visited[257];

void dfs(ll x) {
    visited[x] = 1;

    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(!visited[adj[x][i]]) dfs(adj[x][i]);
    }

    return;
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    bool res = 0;

    for(ll i = 1; i <= n; ++i) {
        if(!visited[i]) {
            res = 1;
            printf("%lld\n", i);
        }
    }
    
    if(!res) printf("0\n");

    return 0;
}