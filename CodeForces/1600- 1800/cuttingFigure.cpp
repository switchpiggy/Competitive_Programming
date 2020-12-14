#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, c[57], r[57], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
char grid[57][57];
bool v[57][57];

ll dfs(ll r, ll c) {
    ll res = 1;
    v[r][c] = 1;
    for(ll i = 0; i < 4; ++i) {
        if(r + dx[i] < 0 || r + dx[i] >= n || c + dy[i] < 0 || c + dy[i] >= m || v[r + dx[i]][c + dy[i]] || grid[r + dx[i]][c + dy[i]] == '.') continue;
        res += dfs(r + dx[i], c + dy[i]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll cnt = 0;
    ll r, c;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            cnt += (grid[i][j] == '#');
            if(grid[i][j] == '#') {
                r = i;
                c = j;
            }
        }
    }

    if(cnt <= 2) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(grid[i][j] != '#') continue;
            memset(v, 0, sizeof(v));
            grid[i][j] =  '.';
            ll cur = dfs(r, c);
            if(cur < cnt - 1) {
                cout << "1\n";
                return 0;
            }
            grid[i][j] = '#';
            r = i;
            c = j;
        }
    }
    
    cout << "2\n";
    return 0;
}