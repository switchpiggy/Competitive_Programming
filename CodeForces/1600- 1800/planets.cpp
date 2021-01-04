#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define pbenqueue priority_queue
ll n, m, k, t, dist[100007];
vector<pair<ll, ll>> adj[100007];
set<ll> nxt[100007];
pbenqueue<pair<ll, ll>> ben;
bool v[100007];
 
ll next(ll to, ll time) {
    if(to == n) return 0;
    ll x = time;
    while(nxt[to].find(x) != nxt[to].end()) x++;
    return x - time;
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
        for(ll j = 0; j < k; ++j) {
            ll a;
            cin >> a;
            nxt[i].insert(a);
        }
    }
 
    for(ll i = 1; i <= n; ++i) dist[i] = LLONG_MAX;
    ll aa = next(1, 0);
    dist[1] = aa;
    ben.push({-aa, 1});
 
    while(!ben.empty()) {
        pair<ll, ll> t = ben.top();
        ben.pop();
        if(v[t.second]) continue;
        if(t.second == n) break;
        v[t.second] = 1;
 
        ll x = -t.first, y = t.second;
        ll cur = next(y, x);
        if(dist[y] < x) continue;
        x += cur, dist[y] += cur;
 
        for(pair<ll, ll> p : adj[y]) {
            //ll cur = next(p.first, x + p.second);
            if(x + p.second < dist[p.first]) {
                dist[p.first] = x + p.second;
                ben.push({-dist[p.first], p.first});
            }
        }
    }
 
    cout << (dist[n] == LLONG_MAX ? -1 : dist[n]) << '\n';
    return 0;
}