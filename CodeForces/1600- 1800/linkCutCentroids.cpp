#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, y, dp[100007], p[100007], c, d, mins = LLONG_MAX;
vector<ll> adj[100007];

void dfs(ll x, ll prev) {
    p[x] = prev;
    ll maxn = 0;
    dp[x] = 1;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] == prev) continue;
        dfs(adj[x][i], x);
        dp[x] += dp[adj[x][i]];
        maxn = max(maxn, dp[adj[x][i]]);
    }

    maxn = max(maxn, n - dp[x]);

    if(mins > maxn) d = 0, c = x, mins = maxn;
    else if(mins == maxn) d = x;
}

ll s = 0;
void findLeaf(ll x, ll prev) {
    if((ll)adj[x].size() == 1) {
        s = x;
        return;
    }
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] == prev) continue;
        findLeaf(adj[x][i], x);
    } 

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        c = d = 0, mins = LLONG_MAX;
        for(ll i = 1; i <= n; ++i) adj[i].clear(), dp[i] = p[i] = 0;
        for(ll i = 0; i < n - 1; ++i) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1, -1);
        if(d == 0) {
            cout << "1 " << adj[1][0] << '\n';
            cout << "1 " << adj[1][0] << '\n';
            continue;
        }

        if(p[c] != d) swap(c, d);
        findLeaf(c, d);
        cout << s << ' ' << p[s] << '\n' << s << ' ' << d << '\n';
    }
}