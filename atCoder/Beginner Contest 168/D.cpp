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
ll n, m, dist[100007], ans[100007], p[100007];
vector<ll> adj[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    inf(dist);
    for(ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dist[1] = 0;
    benq<ll> ben;
    ben.push(1);

    while(!ben.empty()) {
        ll f = ben.front();
        ben.pop();

        for(ll i : adj[f]) {
            if(dist[i] > dist[f] + 1) {
                dist[i] = dist[f] + 1;
                ben.push(i);
            }
        }
    }

    for(ll i = 2; i <= n; ++i) {
        //ll cur = INF;
        for(ll j : adj[i]) {
            if(dist[j] == dist[i] - 1) {
                //cur = dist[j];
                ans[i] = j;
            }
        }

        if(dist[i] == INF) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for(ll i = 2; i <= n; ++i) cout << ans[i] << '\n';
    //cout << '\n';
    return 0;
}