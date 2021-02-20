#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, m, u, v, w;
set<pair<ll, ll>> ben;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(51 * n);
    vector<ll> dist(n * 51, MOD);
    for(ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--;
        v--;
        adj[51 * u].push_back({51 * v + w, 0});
        adj[51 * v].push_back({51 * u + w, 0});
        for(ll j = 1; j <= 50; ++j) {
            adj[51 * v + j].push_back({51 * u, (j + w) * (j + w)});
            adj[51 * u + j].push_back({51 * v, (j + w) * (j + w)});
        }
    }

    dist[0] = 0;
    ben.insert({0, 0});

    while(!ben.empty()) {
        pair<ll, ll> p = *ben.begin();
        ben.erase(p);
        
        //p.first *= -1;
        if(p.first > dist[p.second]) continue;
        for(pair<ll, ll> i : adj[p.second]) {
            if(dist[i.first] > i.second + p.first) {
                ben.erase({-dist[i.first], i.first});
                dist[i.first] = i.second + p.first;
                ben.insert({dist[i.first], i.first});
            }
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(dist[51 * i] == MOD) cout << "-1 ";
        else cout << dist[51 * i] << ' ';
    }

    cout << '\n';
    return 0;
}