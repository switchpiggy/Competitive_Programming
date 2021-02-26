#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
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
ll n, m, dist[200007][4];
vector<pair<ll, ll>> adj[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    inf(dist);
    dist[1][0] = 0;
    pbenq<pair<ll, pair<ll, ll>>> ben;
    ben.push({0, {1, 0}});

    while(!ben.empty()) {
        pair<ll, pair<ll, ll>> t = ben.top();
        ben.pop();
        t.first *= -1;
        if(t.first > dist[t.second.first][t.second.second]) continue;
        ll d = t.first, x = t.second.first, mask = t.second.second;

        for(pair<ll, ll> i : adj[x]) {
            if(dist[i.first][mask] > d + i.second) {
                dist[i.first][mask] = d + i.second;
                ben.push({-dist[i.first][mask], {i.first, mask}});
            }

            if(!(mask & 2)) {
                ll j = mask + 2;
                if(dist[i.first][j] > d) {
                    dist[i.first][j] = d;
                    ben.push({-d, {i.first, j}});
                }
            }

            if(!(mask & 1)) {
                ll j = mask + 1;
                if(dist[i.first][j] > d + 2 * i.second) {
                    dist[i.first][j] = d + 2 * i.second;
                    ben.push({-dist[i.first][j], {i.first, j}});
                }
            }

            if(!mask) {
                if(dist[i.first][3] > d + i.second) {
                    dist[i.first][3] = d + i.second;
                    ben.push({-dist[i.first][3], {i.first, 3}});
                }
            }
        }
    }

    for(ll i = 2; i <= n; ++i) cout << dist[i][3] << ' ';
    cout << '\n';
    return 0;
}