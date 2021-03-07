#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, q, c[200007], buf, p[200007];
vector<pair<ll, ll>> e;
vector<pair<ll, bool>> op[200007];
vector<ll> adj[200007];

void find_parent(ll x, ll par) {
    p[x] = par;
    for(ll i : adj[x]) {
        if(i != par) {
            find_parent(i, x);
        }
    }
}

void dfs(ll x, ll add) {
    ll cur = add;
    for(pair<ll, bool> i : op[x]) {
        if(i.second) {
            cur += i.first;
        } else {
            cur -= i.first;
            buf += i.first;
        }
    }

    c[x] += cur;
    for(ll i : adj[x]) {
        if(i != p[x]) {
            dfs(i, cur);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        e.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_parent(1, -1);

    cin >> q;
    for(ll i = 0; i < q; ++i) {
        ll t, k, x;
        cin >> t >> k >> x;
        k--;
        if(t == 1) { //1 - adding to subtree, 0 - subtracting and adding to buffer
            if(p[e[k].first] == e[k].second) op[e[k].first].push_back({x, 1});
            else op[e[k].second].push_back({x, 0});
        } else {
            if(p[e[k].second] == e[k].first) op[e[k].second].push_back({x, 1});
            else op[e[k].first].push_back({x, 0});
        }
    }

    dfs(1, 0);

    for(ll i = 1; i <= n; ++i) cout << c[i] + buf << '\n';
    return 0;
}