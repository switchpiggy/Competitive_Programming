#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> adj[50005];
bool visited[50005];
ll parent[50005];

ll n, r1, r2, temp;

void dfs(ll x, ll prev) {

    if(visited[x]) return;
    visited[x] = true;

    parent[x] = prev;

    for(ll i = 0; i < adj[x].size(); ++i) {
        dfs(adj[x][i], x);
    }

    return;
}

int main() {
    scanf("%lld %lld %lld", &n, &r1, &r2);
    for(ll i = 1; i <= n; ++i) {
        if(i != r1) {
            scanf("%lld", &temp);
            adj[temp].push_back(i);
            adj[i].push_back(temp);
        }
    }
    dfs(r2, r2);
    for(ll i = 1; i <= n; ++i) {
        if(i != r2) printf("%lld ", parent[i]);
    }
}