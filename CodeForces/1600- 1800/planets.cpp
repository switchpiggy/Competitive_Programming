#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define pbenqueue priority_queue
ll n, m, k, t, dist[100007];
vector<pair<ll, ll>> adj[100007];
vector<ll> nxt[100007], cur[100007];
pbenqueue<pair<ll, ll>> ben;
vector<ll> v;

ll next(ll to, ll time) {
    auto itr = lower_bound(cur[to].begin(), cur[to].end(), time);
    if(itr == cur[to].end() || *itr != time) return 0;
    return *((itr - cur[to].begin()) + nxt[to].begin()) - *itr;
}

ll dijkstra() {
    for(ll i = 1; i <= n; ++i) dist[i] = LLONG_MAX;
    dist[1] = 0;
    ben.push({next(1, 0), 1});

    while(!ben.empty()) {
        pair<ll, ll> t = ben.top();
        ben.pop();

        ll x = t.first, y = t.second;
        if(dist[y] < x) continue;

        for(pair<ll, ll> p : adj[y]) {
            if(x + p.second + next(p.first, x + p.second) <= dist[p.first]) {
                dist[p.first] = x + p.second + next(p.first, x + p.second);
                ben.push({dist[p.first], p.first});
            }
        }
    }

    return (dist[n] == LLONG_MAX ? -1 : dist[n]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    for(ll i = 1; i <= n; ++i) {
        cin >> k;
        v.clear();
        for(ll j = 0; j < k; ++j) {
            ll a;
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());

        vector<ll> c(k);
        if(!v.empty()) c.back() = v.back() + 1;
        for(ll i = k - 2; i >= 0; --i) {
            if(v[i] == v[i + 1] - 1) c[i] = c[i + 1];
            else c[i] = v[i] + 1;
        }

        nxt[i] = c, cur[i] = v;
    }

    cout << dijkstra() << '\n';
    return 0;
}