#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[1007][1007], dist[1007][1007], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
priority_queue<pair<ll, pair<pair<ll, ll>, pair<ll, ll>>>, vector<pair<ll, pair<pair<ll, ll>, pair<ll, ll>>>>, greater<pair<ll, pair<pair<ll, ll>, pair<ll, ll>>>>> pq;

void dijkstra() {
    pq.push({0, {{0, 0}, {0, 0}}});
    dist[0][0] = 0;
    while(!pq.empty()) {
        pair<ll, pair<pair<ll, ll>, pair<ll, ll>>> p = pq.top();
        pq.pop();

        if(p.first > dist[p.second.first.first][p.second.first.second]) continue;
        ll x = p.second.first.first, y = p.second.first.second, slide = p.second.second.second, smell = p.second.second.first;
        for(ll i = 0; i < 4; ++i) {
            if(dx[i] + x >= n || dx[i] + x < 0 || dy[i] + y >= m || dy[i] + m < 0) continue;
            if(smell && a[dx[i] + x][dy[i] + y]) 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> a[i][j];
    }

    dijkstra();

    if(!dist[n - 1][m - 1]) cout << "-1\n";
    else cout << dist[n - 1][m - 1] << '\n';

    return 0;
}