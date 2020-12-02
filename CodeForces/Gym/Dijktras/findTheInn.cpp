#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p, m, x, y, w, t, k, dist[30007];
vector<pair<ll, ll>> adj[30007];
bool pine[30007];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

void dijkstra() {
    pq.push({0, 1});
    while(!pq.empty()) {
        pair<ll, ll> p = pq.top();
        pq.pop();
        if(dist[p.second] < p.first) continue;
        for(ll i = 0; i < (ll)adj[p.second].size(); ++i) {
            if(dist[p.second] + adj[p.second][i].second < dist[adj[p.second][i].first]) {
                dist[adj[p.second][i].first] = dist[p.second] + adj[p.second][i].second;
                pq.push({dist[adj[p.second][i].first], adj[p.second][i].first});
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t >> k >> p;
    for(ll i = 0; i < p; ++i) {
        cin >> x;
        pine[x] = 1;
    }

    for(ll i = 0; i < m; ++i) {
        cin >> x >> y >> w;
        adj[x].push_back({y, 60 * w + ((pine[y]) ? k : 0)});
    }

    for(ll i = 2; i <= n; ++i) dist[i] = LONG_LONG_MAX;
    dijkstra();

    //for(ll i = 1; i <= n; ++i) cout << dist[i] << ' ';

    if(dist[n] > t * 60) cout << "-1\n";
    else cout << dist[n] << '\n';
    return 0;
}