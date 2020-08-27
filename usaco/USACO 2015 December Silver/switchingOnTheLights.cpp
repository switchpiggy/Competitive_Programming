#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool v[107][107];
ll state[107][107], n, m, x, y, a, b, dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};
vector<pair<ll, ll>> switches[107][107];
ll res = 0;

bool hasVisitedNeighbor(ll r, ll c) {
    for(ll i = 0; i < 4; ++i) {
        if(v[r + dx[i]][c + dy[i]] && state[r + dx[i]][c + dy[i]] == 1 && r + dx[i] <= n && r + dx[i] > 0 && c + dy[i] <= n && c + dy[i] > 0) return 1;
    }

    return 0;
}


void dfs(ll r, ll c) {
    if(v[r][c]) return;
    v[r][c] = 1;
    for(ll i = 0; i < switches[r][c].size(); ++i) {
        if(!state[switches[r][c][i].first][switches[r][c][i].second]) {
            state[switches[r][c][i].first][switches[r][c][i].second] = 1;
            if(hasVisitedNeighbor(switches[r][c][i].first, switches[r][c][i].second)) dfs(switches[r][c][i].first, switches[r][c][i].second);
        }
    }

    for(ll i = 0; i < 4; ++i) {
        if(r + dx[i] > 0 && r + dx[i] <= n && c + dy[i] <= n && c + dy[i] > 0 && state[r + dx[i]][c + dy[i]] == 1) dfs(r + dx[i], c + dy[i]);
    }
    return;
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out" , "w", stdout);

    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
        switches[x][y].push_back(make_pair(a, b));
    }

    state[1][1] = 1;
    dfs(1, 1);

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(state[i][j]) res++;
        }
    }

    printf("%lld\n", res);
    return 0;
}