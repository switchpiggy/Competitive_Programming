#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define p_benqueue priority_queue
ll n, m, dist[1007];
vector<ll> e;
p_benqueue<pair<ll, ll>> ben;
vector<pair<ll, pair<ll, ll>>> adj[1007];

ll dijkstra(ll x, ll flow) {
    for(ll i = 1; i <= n; ++i) dist[i] = LLONG_MAX;
    dist[x] = 0;
    ben.push({0, x});

    while(!ben.empty()) {
        pair<ll, ll> p = ben.top();
        ben.pop();
        ll a = p.first, b = p.second;
        if(a < dist[b]) continue;
        for(pair<ll, pair<ll, ll>> k : adj[b]) {
            if(k.second.second < flow) continue;
            if(dist[b] + k.second.first < dist[k.first]) {
                dist[k.first] = dist[b] + k.second.first;
                ben.push({dist[k.first], k.first});
            }
        }
    }

    return dist[n];
}

void fileIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO("pump");
    
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        e.push_back(d);
        adj[a].push_back({b, {c, d}});
        adj[b].push_back({a, {c, d}});
    }

    sort(e.begin(), e.end());

    ll cur = 0, ans = 0;
    while(cur < m) {
        ll minFlow = e[cur], res = dijkstra(1, minFlow);
        //cout << minFlow << ' ' << res << '\n';
        if(res != LLONG_MAX) ans = max(ans, (1000000 * minFlow)/res);
        else break;
        //cout << minFlow << '\n';
        while(cur < m && e[cur] == minFlow) cur++; 
    }

    cout << ans << '\n';
    return 0;
}