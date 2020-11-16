#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
ll n, m, a, b, w, dist[100007], p[100007];
vector<pair<ll, ll>> adj[100007];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
 
void dijkstra() {
    dist[1] = 0;
    pq.push({0, 1});
 
    while(!pq.empty()) {
        pair<ll, ll> t = pq.top();
        pq.pop();
 
        if(t.first > dist[t.second]) continue;
        for(ll i = 0; i < (ll)adj[t.second].size(); ++i) {
            if(adj[t.second][i].second + dist[t.second] <= dist[adj[t.second][i].first]) {
                dist[adj[t.second][i].first] = adj[t.second][i].second + dist[t.second];
                p[adj[t.second][i].first] = t.second;
                pq.push({dist[adj[t.second][i].first], adj[t.second][i].first});
            }
        }
    }
}
 
void printans(ll x) {
    if(p[x] != -1) printans(p[x]);
    cout << x << ' ';
    return;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
 
    for(ll i = 1; i <= n; ++i) {
        dist[i] = LONG_LONG_MAX;
        p[i] = -1;
    }
 
    dijkstra();

    //for(ll i = 1; i <= n; ++i) cout << dist[i] << ' ';
 
    if(dist[n] == LONG_LONG_MAX) {
        cout << "-1\n";
        return 0;
    }
 
    printans(n);
    return 0;
}