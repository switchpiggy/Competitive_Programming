#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue

void fileIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

ll n, m, p[200007], res[200007];
vector<ll> adj[2000007], v[200007];

benqueue<ll> ben;

void uni(ll x, ll y) {
    x = p[x], y = p[y];
    if(x == y) return;
    if(v[x].size() > v[y].size()) swap(x, y);

    for(ll i = 0; i < (ll)v[x].size(); ++i) {
        p[v[x][i]] = y;
        v[y].push_back(v[x][i]);
    }

    adj[y].insert(adj[y].end(), adj[x].begin(), adj[x].end());
    adj[x].clear();

    if(adj[y].size() > 1) ben.push(y);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO("fcolor");
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        v[i].push_back(i);
        p[i] = i;
    }

    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(ll i = 1; i <= n; ++i) {
        if(adj[i].size() > 1) ben.push(i);
    }

    while(ben.size()) {
        ll x = ben.front();
        //ben.pop();
        if(adj[x].size() <= 1) {
            ben.pop();
            continue;
        }

        ll cur = adj[x].back();
        adj[x].pop_back();
        if(p[adj[x].back()] == p[cur]) continue;
        uni(adj[x].back(), cur);
        //if(adj[x].size() > 1) ben.push(x);
    }

    ll cur = 1;
    for(ll i = 1; i <= n; ++i) {
        if(!res[p[i]]) res[p[i]] = cur++;
        cout << res[p[i]] << '\n';
    }

    //cout << '\n';
    return 0;
}