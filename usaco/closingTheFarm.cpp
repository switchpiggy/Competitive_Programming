#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p[200007], r[200007], res[200007], a[200007], pos[200007];
vector<ll> adj[200007];
vector<pair<ll, ll>> v;

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);

    p[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    iota(p + 1, p + n + 1, 1);
    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(ll i = 0; i < m; ++i) {
        if(pos[v[i].first] < pos[v[i].second]) adj[v[i].first].push_back(v[i].second);
        else adj[v[i].second].push_back(v[i].first);
    }
    ll open = 0;
    for(ll i = n; i >= 1; --i) {
        open++;
        for(ll j = 0; j < (ll)adj[a[i]].size(); ++j) {
            if(get(a[i]) != get(adj[a[i]][j])) {
                uni(a[i], adj[a[i]][j]);
                open--;
            }            
        }
        res[i] = (open <= 1);
        //for(ll i = 1; i <= n; ++i) cout << p[i] << ' ';
        //cout << '\n';
    }

    for(ll i = 1; i <= n; ++i) cout << (res[i] ? "YES\n" : "NO\n");
    return 0;
}