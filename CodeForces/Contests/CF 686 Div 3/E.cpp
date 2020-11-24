#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll good = 0;
ll t, n;
bool v[200007];
vector<ll> adj[200007];

void bfs(ll x, ll len) {
    if(v[x]) return;
    if(len) good++; 
    v[x] = 1;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        bfs(adj[x][i], len + 1);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        good = 0;
        cin >> n;
        for(ll i = 1; i <= n; ++i) adj[i].clear();
        for(ll i = 0; i < n; ++i) {
            ll l, r;
            cin >> l >> r;
            adj[l].push_back(r);
            adj[r].push_back(l);
        }

        for(ll i = 1; i <= n; ++i) {
            memset(v, 0, sizeof(v[0]) * (n + 1));
            bfs(i, 0);
        }

        cout << good/2 << '\n';
    }
}