#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
char a[51][51];
bool v[51][51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) cin >> a[i][j];
        }

        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                if(a[i][j] != 'B') continue;
                if(i) {
                    if(a[i - 1][j] == 'G') ok = 1;
                    if(a[i - 1][j] == '.') a[i - 1][j] = '#';
                }
                if(j) {
                    if(a[i][j - 1] == 'G') ok = 1;
                    if(a[i][j - 1] == '.') a[i][j - 1] = '#';
                }

                if(i < n - 1) {
                    if(a[i + 1][j] == 'G') ok = 1;
                    if(a[i + 1][j] == '.') a[i + 1][j] = '#';
                }

                if(j < m - 1) {
                    if(a[i][j + 1] == 'G') ok = 1;
                    if(a[i][j + 1] == '.') a[i][j + 1] = '#';
                }
            }
        }

        queue<pair<ll, ll>> q;
        if(a[n - 1][m - 1] == '.') {
            q.push({n - 1, m - 1});
            v[n - 1][m - 1] = 1;
        }

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) v[i][j] = 0;
        }

        while(!q.empty()) {
            pair<ll, ll> p = q.front();
            q.pop();
            //if(a[p.first][p.second] == '#') break;
            for(ll i = 0; i < 4; ++i) {
                if(p.first + dx[i] < 0 || p.first + dx[i] >= n || p.second + dy[i] < 0 || p.second + dy[i] >= m) continue;
                if(a[p.first + dx[i]][p.second + dy[i]] == '#' || v[p.first + dx[i]][p.second + dy[i]]) continue;
                q.push({p.first + dx[i], p.second + dy[i]});
                v[p.first + dx[i]][p.second + dy[i]] = 1;
            }
        }

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                //cout << a[i][j] << ' ';
                if(a[i][j] == 'B' && v[i][j]) ok = 1;
                if(a[i][j] == 'G' && !v[i][j]) ok = 1;
            }
        }

        cout << (ok ? "No\n" : "Yes\n");
    }

    return 0;
}