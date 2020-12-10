#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[307], adj[307][307];
vector<vector<ll>> res;
bool vis[307];
vector<ll> cur;

void dfs(ll x) {
    vis[x] = 1;
    cur.push_back(x);

    for(ll i = 0; i < n; ++i) {
        if(adj[x][i] && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> p[i];
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            char c;
            cin >> c;
            adj[i][j] = (c == '1');
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(!vis[i]) {
            //cout << i << '\n';
            cur.clear();
            dfs(i);
            res.push_back(cur);
        }
    }

    //cout << (ll)res.size() << '\n';
    for(ll i = 0; i < (ll)res.size(); ++i) {
        vector<ll> v = res[i];
        cur.clear();
        for(ll j = 0; j < (ll)v.size(); ++j) cur.push_back(p[v[j]]);

        sort(cur.begin(), cur.end());
        sort(v.begin(), v.end());

        for(ll j = 0; j < (ll)v.size(); ++j) {
            //cout << cur[j] << ' ';
            p[v[j]] = cur[j];
        }
    }

    for(ll i = 0; i < n; ++i) cout << p[i] << ' ';
}