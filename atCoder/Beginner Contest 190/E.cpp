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
#define INF 0x3f3f3f3f3f3f3f3f
#define flout cout << fixed << setprecision(12)
ll n, m, dist[18][100007], dp[(1 << 18)][18], c[18], k;
vector<ll> adj[100007];

void calc(ll mask, ll last) {
    if(dp[mask][last] != INF) return;

    for(ll i = 0; i < k; ++i) {
        if(i != last && dist[i][c[last]] != INF && (mask & (1 << i))) {
            calc(mask - (1 << last), i);
            if(dp[mask - (1 << last)][i] == INF) continue;
            dp[mask][last] = min(dp[mask][last], dp[mask - (1 << last)][i] + dist[i][c[last]]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    inf(dist);
    inf(dp);
    //cout << dp[0][0] << '\n';
    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> k;
    for(ll i = 0; i < k; ++i) cin >> c[i];
    for(ll i = 0; i < k; ++i) {
        //cin >> c[i];
        //m0(v);
        benq<ll> ben;
        ben.push(c[i]);
        dist[i][c[i]] = 0;
        while(!ben.empty()) {
            ll f = ben.front();
            ben.pop();
            //v[f] = 1;

            for(ll j : adj[f]) {
                if(dist[i][j] != INF) continue;
                dist[i][j] = dist[i][f] + 1;
                ben.push(j);
            }
        }

        dp[(1 << i)][i] = 0;
    }

    for(ll i = 0; i < k; ++i) {
        if(dist[i][c[0]] == INF) {
            cout << "-1\n";
            return 0;
        }
    }

    ll ans = INF;
    for(ll i = 0; i < k; ++i) {
        calc((1 << k) - 1, i);
        ans = min(ans, 1 + dp[(1 << k) - 1][i]);
    }

    //cout << ans << '\n';
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}