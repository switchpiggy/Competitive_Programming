#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b, num[8];
vector<ll> adj[8];
bool taken[7][7], visited[8];

void dfs(ll v) {
    if(visited[v]) return;
    visited[v] = 1;

    ll cur = 1;
    for(ll i = 0; i < adj[v].size(); ++i) {
        if(!num[adj[v][i]]) {
            while(taken[num[v]][cur] && cur <= 6) cur++;
            if(cur >= 7) {
                continue;
            }

            num[adj[v][i]] = cur;
            taken[num[v]][cur] = 1;
        } else {
            if(!taken[num[v]][num[adj[v][i]]]) {
                taken[num[v]][num[adj[v][i]]] = 1;
            }
        }
    }

    for(ll i = 0; i < adj[v].size(); ++i) {
        dfs(adj[v][i]);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    num[1] = 1;
    dfs(1);

    ll ans = 0;

    /*for(ll i = 1; i <= n; ++i) {
        cout << visited[i] << ' ' << num[i] << endl;
    }*/

    for(ll i = 1; i <= 6; ++i) {
        for(ll j = i; j <= 6; ++j) {
            //cout << taken[i][j] << ' ';
            if(taken[i][j]) ans++;
        }

        //cout << endl;
    }

    cout << ans << endl;
    return 0;
}