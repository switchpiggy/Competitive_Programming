#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
char grid[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) cin >> grid[i][j];
    }

    if(n%3 == 0 && grid[1][1] != grid[n/3 + 1][1] && grid[n/3 + 1][1] != grid[(2 * n)/3 + 1][1] && grid[1][1] != grid[2 * n/3 + 1][1]) {
        bool ok = 1;
        //cout << "y\n";
        for(ll c = 0; c < 3; ++c) {
            for(ll i = c * (n/3) + 1; i <= (c + 1) * n/3; ++i) {
                for(ll j = 1; j <= m; ++j) {
                    if(grid[i][j] != grid[c * (n/3) + 1][1]) {
                        ok = 0;
                        break;
                    }
                }
            }
        }

        if(ok) {
            cout << "YES\n";
            return 0;
        }
    }

    if(m%3 == 0 && grid[1][1] != grid[1][m/3 + 1] && grid[1][2 * m/3 + 1] != grid[1][m/3 + 1] && grid[1][1] != grid[1][2 * m/3 + 1]) {
        bool ok = 1;
        //cout << "z\n";
        for(ll c = 0; c < 3; ++c) {
            for(ll i = 1; i <= n; ++i) {
                for(ll j = c * (m/3) + 1; j <= (c + 1) * (m/3); ++j) {
                    if(grid[i][j] != grid[1][c * m/3 + 1]) {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        
        if(ok) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}