#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[200007], mins[200007], deg[200007], dp[200007];
vector<ll> adj[200007];
bool visited[200007];

void find_min(ll x) {
    visited[x] = 1;
    mins[x] = INT_MIN;
    for(ll i : adj[x]) {
        if(!visited[i]) find_min(i);
        mins[x] = max({mins[x], mins[i], a[i]});
    }
}

void dfs(ll x) {
    visited[x] = 1;
    dp[x] = mins[x] - a[x];
    for(ll i : adj[x]) {
        if(!visited[i]) dfs(i);
        dp[x] = max(dp[x], dp[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        //mins[i] = a[i];
    }

    for(ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        deg[y]++;
    }

    //ll start = 1;
    for(ll i = 1; i <= n; ++i) {
        if(!deg[i]) {
            find_min(i);
        }
    }    

    memset(visited, 0, sizeof(visited));

    for(ll i = 1; i <= n; ++i) {
        if(!deg[i]) {
            dfs(i);
        }
    }

    ll ans = LLONG_MIN;
    for(ll i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    //for(ll i = 1; i <= n; ++i) cout << mins[i] << ' ';

    cout << ans << '\n';
    return 0;
}