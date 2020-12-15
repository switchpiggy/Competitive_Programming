#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, w, p[1007], r[1007], dist[1007][1007];
char level[1007][11][11];
vector<ll> adj[1007];
vector<pair<ll, ll>> edges;

void dfs(ll x, ll prev) {
    if(prev != -1) cout << x << ' ' << prev << '\n';
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(prev == adj[x][i]) continue;
        dfs(adj[x][i], x);
    }

    return;
}

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);

    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;

    return;
}

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return dist[x.first][x.second] < dist[y.first][y.second];
}

ll kruskal() {
    ll ans = 0;
    sort(edges.begin(), edges.end(), cmp);
    for(ll i = 0; i < (ll)edges.size(); ++i) {
        if(get(edges[i].first) != get(edges[i].second)) {
            uni(edges[i].first, edges[i].second);
            ans += dist[edges[i].first][edges[i].second];
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
            //cout << dist[edges[i].first][edges[i].second] << '\n';
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> w;
    iota(p + 1, p + k + 1, 1);
    for(ll i = 1; i <= k; ++i) {
        for(ll j = 0; j < n; ++j) {
            for(ll jj = 0; jj < m; ++jj) cin >> level[i][j][jj];
        }
    }

    for(ll i = 1; i <= k; ++i) {
        for(ll j = 1; j <= k; ++j) {
            if(i == j) continue;
            for(ll r = 0; r < n; ++r) {
                for(ll c = 0; c < m; ++c) dist[i][j] += (level[i][r][c] != level[j][r][c]) * w;
            }
        }
    }

    for(ll i = 1; i <= k; ++i) {
        dist[0][i] = dist[i][0] = n * m;
        edges.push_back({0, i});
    }

    for(ll i = 1; i <= k; ++i) {
        for(ll j = 1; j <= k; ++j) edges.push_back({i, j});
    }

    cout << kruskal() << '\n';
    dfs(0, -1);
    return 0;
}