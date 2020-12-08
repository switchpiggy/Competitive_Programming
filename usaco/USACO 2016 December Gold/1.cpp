#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dist[1007][1007], d[1007];
vector<pair<ll, ll>> v, t;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

ll mst(ll x) {
    ll res = 0;
    pq.push({0, x});

    while(!pq.empty()) {
        pair<ll, ll> p = pq.top();
        pq.pop();

        if(d[p.second] != -1) continue;
        d[p.second] = p.first;
        res = max(res, p.first);

        for(ll i = 0; i < n; ++i) {
            if(d[i] == -1) {
                pq.push({dist[p.second][i], i});
            }
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            dist[i][j] = (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second);
        }
    }

    for(ll i = 0; i < n; ++i) d[i] = -1;
    cout << mst(0) << '\n';
    return 0;
}