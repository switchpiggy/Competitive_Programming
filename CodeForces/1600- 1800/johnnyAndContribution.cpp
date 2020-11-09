#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<pair<ll, ll>> v;
ll n, m, t[500007], p[500007];
vector<ll> adj[500007];

bool cmp(ll x, ll y) {
    return t[x] < t[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(ll i = 1; i <= n; ++i) {
        cin >> t[i];
        p[i] = i;
    }

    for(ll i = 0; i < m; ++i) {
        if(t[v[i].first] == t[v[i].second]) {
            cout << "-1\n";
            return 0;
        }
    }

    for(ll i = 1; i <= n; ++i) {
        if((ll)adj[i].size() < t[i] - 1) {
            cout << "-1\n";
            return 0;
        } 
        sort(adj[i].begin(), adj[i].end(), cmp);
        
        ll cur = 1;
        for(ll j = 0; j < (ll)adj[i].size(); ++j) {
            if(t[adj[i][j]] == cur) {
                cur++;
            }
        }

        if(cur < t[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    sort(p + 1, p + n + 1, cmp);
    for(ll i = 1; i <= n; ++i) cout << p[i] << ' ';
    cout << '\n';
    return 0;
}