#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
ll n, m, c, s[100007], in[100007];
vector<pair<ll, ll>> adj[100007];

void fileIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO("timeline");
    cin >> n >> m >> c;
    for(ll i = 1; i <= n; ++i) cin >> s[i];
    for(ll i = 0; i < c; ++i) {
        ll a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
        in[b]++;
    }

    benqueue<ll> ben;
    for(ll i = 1; i <= n; ++i) {
        if(in[i] == 0) ben.push(i);
    }

    while(!ben.empty()) {
        ll x = ben.front();
        ben.pop();

        for(ll i = 0; i < (ll)adj[x].size(); ++i) {
            s[adj[x][i].first] = max(s[adj[x][i].first], adj[x][i].second + s[x]);
            if(!(--in[adj[x][i].first])) ben.push(adj[x][i].first);
        }
    }

    for(ll i = 1; i <= n; ++i) cout << s[i] << '\n';
    return 0;
}