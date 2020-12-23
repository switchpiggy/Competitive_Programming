#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<ll> adj[100007];

ll dfs(ll x, ll p) {
    ll deg = 0, res = 0;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] == p) continue;
        res += dfs(adj[x][i], x);
        deg++;
    }

    res += deg;
    ll cur = 1, cnt = 0;
    while(cur <= deg) {
        cur *= 2;
        cnt++;
    }
    
    res += cnt;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(1, -1) << '\n';
    return 0;
}