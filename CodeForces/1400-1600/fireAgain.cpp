#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
ll n, m, k, dist[2007][2007], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

void bfs(ll x, ll y) {
    benqueue<pair<ll, ll>> ben;
    ben.push({x, y});
    dist[x][y] = 0;

    while(!ben.empty()) {
        pair<ll, ll> p = ben.front();
        ben.pop();

        for(ll i = 0; i < 4; ++i) {
            if(p.first + dx[i] > 0 && p.first + dx[i] <= n && p.second + dy[i] > 0 && p.second + dy[i] <= m && dist[p.first + dx[i]][p.second + dy[i]] > dist[p.first][p.second] + 1) {
                dist[p.first + dx[i]][p.second + dy[i]] = min(dist[p.first + dx[i]][p.second + dy[i]], dist[p.first][p.second] + 1); 
                ben.push({p.first + dx[i], p.second + dy[i]});
            }
        }
    }
}

void fileIO(string in, string out) {
    freopen((in + ".txt").c_str(), "r", stdin);
    freopen((out + ".txt").c_str(), "w", stdout);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO("input", "output");
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) dist[i][j] = LLONG_MAX;
    }
    for(ll i = 0; i < k; ++i) {
        ll x, y;
        cin >> x >> y;
        bfs(x, y);
    }

    ll x = 1, y = 1;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) if(dist[i][j] > dist[x][y]) {
            x = i;
            y = j;
        }
    }

    cout << x << ' ' << y << '\n';
    return 0;
}