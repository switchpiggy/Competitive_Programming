#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, adj[6][6], ve[6];

ll djikstra(ll x) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, x));

    ll dist[6];
    for(ll i = 0; i < 6; ++i) dist[i] = INT_MAX;

    //cout << dist[0] << endl;

    dist[x] = 0;
    while(!pq.empty()) {
        pair<ll, ll>t = pq.top();
        pq.pop();

        if(t.first > dist[t.second]) continue;
        for(ll i = 1; i <= n; ++i) {
            if(adj[t.second][i] != -1 && (adj[t.second][i] >= dist[t.second] || dist[t.second] == INT_MAX)) {
                if(adj[t.second][i] < dist[i]) {
                    dist[i] = adj[t.second][i];
                    pq.push(make_pair(dist[i], i));
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) if(dist[i] != INT_MAX) ans++;
    //cout << x << '\n';
    //for(ll i = 1; i <= n; ++i) cout << dist[i] << ' ';
    //cout << '\n';
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        memset(adj, -1, sizeof(adj[0][0]) * 6 * 6);
        cin >> n;
        for(ll i = 1; i <= n; ++i) {
            cin >> ve[i];
        }

        for(ll i = 1; i <= 50; ++i) {
            for(ll j = 1; j <= n; ++j) {
                for(ll k = j + 1; k <= n; ++k) {
                    if(j + ve[j] * i == k + ve[k] * i) {
                        if(adj[j][k] == -1) {
                            adj[j][k] = adj[k][j] = i;
                        }
                    }
                }
            }
        }

        /*for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) cout << adj[i][j] << ' ';
            cout << endl;
        }
        cout << endl;*/

        ll maxn = 1, minn = INT_MAX;
        for(ll i = 1; i <= n; ++i) {
            ll cur = djikstra(i);
            maxn = max(cur, maxn);
            minn = min(cur, minn);
        }

        cout << minn << ' ' << maxn << endl;
    }

    return 0;
}