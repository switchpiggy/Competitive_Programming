#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[200007], b[200007];
vector<ll> adj[200007];
bool v[200007];
ll res1, res2;

void dfs(ll x) {
    v[x] = 1;
    res1 += a[x];
    res2 += b[x];

    for(ll i : adj[x]) {
        if(!v[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 1; i <= n; ++i) cin >> b[i];
    for(ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(ll i = 1; i <= n; ++i) {
        if(v[i]) continue;
        res1 = 0, res2 = 0;
        dfs(i);

        if(res1 != res2) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}