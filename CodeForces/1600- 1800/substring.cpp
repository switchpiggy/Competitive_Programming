#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
ll n, m, x, y, dp[300007][26], deg[300007];
string s;
vector<ll> adj[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    for(ll i = 0; i < m; ++i) {
        cin >> x >> y;
        deg[y]++;
        adj[x].push_back(y);
    }

    benqueue<ll> ben;
    for(ll i = 1; i <= n; ++i) {
        if(deg[i] == 0) ben.push(i);
    }

    for(ll i = 1; i <= n; ++i) {
        dp[i][s[i - 1] - 'a']++;
    }

    ll cnt = 0;
    while(!ben.empty()) {
        ll x = ben.front();
        ben.pop();
        for(ll i : adj[x]) {
            deg[i]--;
            for(ll j = 0; j < 26; ++j) dp[i][j] = max(dp[i][j], dp[x][j] + (j == s[i - 1] - 'a'));
            if(!deg[i]) ben.push(i);
        }

        cnt++;
    }

    if(cnt != n) {
        cout << "-1\n";
        return 0;
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 0; j < 26; ++j) ans = max(ans, dp[i][j]);
    }

    cout << ans << '\n';
    return 0;
}