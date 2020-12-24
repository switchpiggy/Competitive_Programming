#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[200007];
vector<ll> adj[200007];

pair<ll, ll> dfs(ll x, ll par) {
    p[x] = par;
    ll dist = 0, cur = x;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(par == adj[x][i]) continue;
        pair<ll, ll> res = dfs(adj[x][i], x);
        if(res.second > dist) {
            dist = res.second;
            cur = res.first;
        }
    }

    return {cur, dist + 1};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    pair<ll, ll> a = dfs(1, -1), b = dfs(a.first, -1);
    //cout << a.first << ' ' << b.first << '\n';

    vector<ll> res;
    res.push_back(b.first);
    while(p[res.back()] != -1) {
        res.push_back(p[res.back()]);
    }

    //for(ll i : res) cout << i << ' ';

    ll ans = (ll)res.size(), maxn = 0, maxRes = 0;
    for(ll i = 0; i < (ll)res.size(); ++i) {
        for(ll j = 0; j < (ll)adj[res[i]].size(); ++j) {
            if((i && res[i - 1] == adj[res[i]][j]) || (i < (ll)res.size() - 1 && res[i + 1]  == adj[res[i]][j])) continue;
            pair<ll, ll> r = dfs(adj[res[i]][j], res[i]);
            if(r.second > maxn) {
                maxn = r.second;
                maxRes = r.first;
            }
        }
    }

    cout << ans + maxn - 1 << '\n';
    cout << res[0] << ' ' << res.back() << ' ';
    if(maxn) cout << maxRes << '\n';
    else cout << p[res[0]] << '\n';
    return 0;
}