#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, adj[6][6], ve[6], dist[6];
bool visited[6];

ll djikstra(ll x) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, x));

    memset(dist, 1000000, sizeof(dist));

    dist[x] = 0;
    while(!pq.empty()) {
        pair<ll, ll>t = pq.top();
        pq.pop();

        visited[t.second] = 1;

        if(t.first > dist[t.second]) continue;
        for(ll i = 1; i <= n; ++i) {
            if(adj[t.second][i] != -1 && adj[t.second][i] >= dist[t.second]) {
                if(adj[t.second][i] < dist[i]) {
                    dist[i] = adj[t.second][i];
                    pq.push(make_pair(dist[i], i));
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) if(visited[i]) ans++;
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
                for(ll k = 1; k <= n; ++k) {
                    if(j == k) continue;
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
            memset(visited, 0, sizeof(visited));
            //memset(dist, INT_MAX, sizeof(dist));
            ll cur = djikstra(i);
            maxn = max(cur, maxn);
            minn = min(cur, minn);
        }

        cout << minn << ' ' << maxn << endl;
    }

    return 0;
}