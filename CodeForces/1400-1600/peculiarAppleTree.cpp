#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<ll> adj[100007];
map<ll, ll> occ;

void dfs(ll v, ll cur) {
    occ[cur]++;
    for(ll i = 0; i < (ll)adj[v].size(); ++i) {
        dfs(adj[v][i], cur + 1);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 2; i <= n; ++i) {
        ll p;
        cin >> p;
        adj[p].push_back(i);
    }

    dfs(1, 0);

    ll ans = 0;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        ans += i->second%2;
    }

    cout << ans << '\n';
    return 0;
}