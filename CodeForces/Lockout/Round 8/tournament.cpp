#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<ll> adj[57];
bool ok[57][57];
bool visited[57];

bool dfs(ll x, ll y) {
    if(x == y) return 1;
    visited[x] = 1;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(visited[adj[x][i]]) continue;
        if(dfs(adj[x][i], y)) return 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < (n * (n - 1))/2 - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        ok[x][y] = ok[y][x] = 1;
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(i == j) continue;
            if(!ok[i][j]) {
                if(dfs(i, j)) cout << i << ' ' << j << '\n';
                else cout << j << ' ' << i << '\n';
                return 0;
            }
        }
    }
}