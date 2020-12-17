#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b, dist[307][307], c, l, q, d[307][307];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            dist[i][j] = INT_MAX;
            d[i][j] = INT_MAX;
        }
    }

    for(ll i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        dist[b][a] = dist[a][b] = c;
    }

    for(ll k = 1; k <= n; ++k) {
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) {
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(dist[i][j] <= l) d[i][j] = d[j][i] = 1;
        }
    }

    for(ll k = 1; k <= n; ++k) {
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) {
                if(d[i][k] == INT_MAX || d[k][j] == INT_MAX) continue;
                d[j][i] = d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cin >> q;
    while(q--) {
        cin >> a >> b;
        if(d[a][b] == INT_MAX) d[a][b] = 0;
        cout << d[a][b] - 1 << '\n';
    }

    return 0;
}