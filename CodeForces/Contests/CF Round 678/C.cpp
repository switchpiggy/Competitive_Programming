#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[200007], a[200007];
vector<ll> adj[200007];

bool cmp(ll x, ll y) {
    return a[x] < a[y];
}

void dfs(ll x, ll cur) {
    if((ll)adj[x].size()) {
        a[x] += cur;
        return;
    }

    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 2; i <= n; ++i) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) cout << a[i] << ' ';

    cout << ans << '\n';
    return 0;
}