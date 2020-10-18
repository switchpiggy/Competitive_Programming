#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, grid[27][27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> grid[i][j];
    }

    bool ok = 0;
    for(ll i = 0; i < n; ++i) {
        ll cnt = 0;
        for(ll j = 0; j < m; ++j) {
            if(grid[i][j] != j + 1) cnt++;
        }

        if(cnt > 2) {
            ok = 1;
            break;
        }
    }

    if(!ok) {
        cout << "YES\n";
        return 0;
    }

    for(ll i = 0; i < m; ++i) {
        for(ll j = 0; j < m; ++j) {
            bool ok = 0;

            for(ll k = 0; k < n; ++k) {
                swap(grid[k][i], grid[k][j]);

                ll cnt = 0;
                for(ll l = 0; l < m; ++l) {
                    if(grid[k][l] != l + 1) cnt++;
                }

                swap(grid[k][i], grid[k][j]);

                if(cnt > 2) {
                    ok = 1;
                    break;
                }
            }

            if(!ok) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}