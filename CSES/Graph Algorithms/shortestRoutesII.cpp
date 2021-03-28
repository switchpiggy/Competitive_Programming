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
ll n, m, q, a, b, c, dist[507][507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inf(dist);
    cin >> n >> m >> q;
    for(ll i = 1; i <= n; ++i) dist[i][i] = 0;

    while(m--) {
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    for(ll k = 1; k <= n; ++k) {
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) {
                if(dist[i][k] == INF || dist[j][k] == INF) continue;
                dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[j][k]);
            }
        }
    }

    while(q--) {
        cin >> a >> b;
        if(dist[a][b] == INF) cout << "-1\n";
        else cout << dist[a][b] << '\n';
    }

    return 0;
}