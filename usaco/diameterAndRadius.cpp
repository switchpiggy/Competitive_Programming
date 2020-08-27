#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, u, v;
vector<ll> adj[100007];
bool visited[100007];

pair<ll, ll> bfs(ll x) {
    memset(visited, 0, sizeof(viisted));
    queue<ll> q;
    q.push(x);

    ll last = 0, dist = 0;

    while(!q.empty()) {
        ll f = q.front();
        q.pop();

        last = f;
        visited[f] = 1;

        for(ll i = 0; i < adj[f].size(); ++i) {
            if(!visited[adj[f][i]]) q.push(adj[f][i]);
        }

        dist++;
    }

    return last;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n - 1; ++i) {
        scanf("%lld %lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<ll, ll> last = bfs(1);
    pair<ll, ll> last1 = bfs(last.first);

    printf("%lld %lld\n", last1.second, (ll)ceil(last1.second/2))

    
}