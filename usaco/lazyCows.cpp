#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long int ll;
ll n, m, k, numCows[100007], a, b;
vector<ll> adj[100007];
ll visited[100007];

void dfs(ll cur) {
    queue<pair<ll, ll>> q;
    q.push(make_pair(cur, 0));
    while(!q.empty()) {
        pair<ll, ll> f = q.front();
        q.pop();

        if(f.second > k) return;

        visited[f.first] = f.second;

        for(ll i = 0; i < adj[f.first].size(); ++i) {
            if(f.second + 1 <= visited[adj[f.first][i]] || !visited[adj[f.first][i]]) q.push(make_pair(adj[f.first][i], f.second + 1));
        }
    }

    return;
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i = 1; i <= n; ++i) scanf("%lld", &numCows[i]);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    dfs(n);

    ll res = 0;
    for(ll i = 2; i < n; ++i) {
        if(visited[i] && visited[i] <= k) res += numCows[i];
    }
    res += numCows[n] + numCows[1];

    printf("%lld\n", res);

    return 0;
}