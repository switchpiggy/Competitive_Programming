#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, ans[100007];
vector<ll> adj[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    bool ok = 0;
    for(ll i = 0; i < n; ++i) {
        ll s, r;
        cin >> s >> r;
        if(r >= 0) ok = 1;
        adj[s].push_back(r);
    }

    if(!ok) {
        cout << 0 << '\n';
        return 0;
    }

    for(ll i = 1; i <= m; ++i) {
        sort(adj[i].begin(), adj[i].end(), greater<ll>());
        for(ll j = 1; j < (ll)adj[i].size(); ++j) adj[i][j] += adj[i][j - 1];
        for(ll j = 0; j < (ll)adj[i].size(); ++j) {
            if(adj[i][j] >= 0) ans[j + 1] += adj[i][j];
        }
    }

    ll res = 0;
    for(ll i = 1; i <= n; ++i) res = max(res, ans[i]);

    cout << res << '\n';
    return 0;
}