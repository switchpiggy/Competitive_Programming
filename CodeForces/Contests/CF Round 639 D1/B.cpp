#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m0(x) memset(x, 0, sizeof(x))
#define m1(x) memset(x, 1, sizeof(x))
#define mn1(x) memset(x, -1, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll n, m, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
char grid[1007][1007];
bool v[1007][1007];

ll dfs(ll x, ll y) {
    v[x][y] = 1;
    ll res = 1;
    for(ll i = 0; i < 4; ++i) {
        if(x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < m && y + dy[i] >= 0 && !v[x + dx[i]][y + dy[i]] && grid[x + dx[i]][y + dy[i]] == '#') {
            res += dfs(x + dx[i], y + dy[i]);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll res = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            res += (grid[i][j] == '#');
        }
    }

    if(!res) {
        cout << "0\n";
        return 0;
    }

    bool r = 0, c = 0;
    for(ll i = 0; i < n; ++i) {
        ll cnt = 0;
        for(ll j = 0; j < m; ++j) {
            if(grid[i][j] == '#') {
                if(!j || grid[i][j - 1] == '.') cnt++;
            }
        }

        if(cnt > 1) {
            cout << "-1\n";
            return 0;
        }

        if(!cnt) r = 1;
    }

    for(ll i = 0; i < m; ++i) {
        ll cnt = 0;
        for(ll j = 0; j < n; ++j) {
            if(grid[j][i] == '#') {
                if(!j || grid[j - 1][i] == '.') cnt++;
            }
        }

        if(cnt > 1) {
            cout << "-1\n";
            return 0;
        }

        if(!cnt) c = 1;
    }

    if(r^c) {
        cout << "-1\n";
        return 0;
    }

    ll ans = 0;
    bool ok = 1;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(!v[i][j] && grid[i][j] == '#') {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << (ok ? ans : -1) << '\n';
    return 0;
}