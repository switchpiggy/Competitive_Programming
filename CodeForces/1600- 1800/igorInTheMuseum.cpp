#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k;
char grid[1007][1007];
ll x, y, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}, ans[1007][1007];
bool v[1007][1007];

ll dfs(ll r, ll c) {
    if(v[r][c]) return 0;
    v[r][c] = 1;

    ll ans = 0;
    for(ll i = 0; i < 4; ++i) {
        if(r + dx[i] < n && r + dx[i] >= 0 && c + dy[i] < m && c + dy[i] >= 0) {
            if(grid[r + dx[i]][c + dy[i]] == '.') ans += dfs(r + dx[i], c + dy[i]);
            else ans++;
        } 
    }

    return ans;
}

void fill(ll r, ll c, ll val) {
    ans[r][c] = val;
    for(ll i = 0; i < 4; ++i) {
        if(r + dx[i] < n && r + dx[i] >= 0 && c + dy[i] < m && c + dy[i] >= 0) {
            if(grid[r + dx[i]][c + dy[i]] == '.') {
                grid[r + dx[i]][c + dy[i]] = '*';
                fill(r + dx[i], c + dy[i], val);
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> grid[i][j];
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(!v[i][j] && grid[i][j] == '.') {
                ll cur = dfs(i, j);
                fill(i, j, cur);
            }
        }
    }

    for(ll i = 0; i < k; ++i) {
        cin >> x >> y;
        x--;
        y--;
        cout << ans[x][y] << '\n';
    }

    return 0;
}