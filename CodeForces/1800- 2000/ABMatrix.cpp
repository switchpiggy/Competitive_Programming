#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, a, b;
bool grid[57][57];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m >> a >> b;
        memset(grid, 0, sizeof(grid));
        if(n * a != m * b) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        ll shift = 0;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < a; ++j) grid[i][(j + shift)%m] = 1;
            shift += a;
        }

        for(ll i = 0; i < n; ++i, cout << '\n') {
            for(ll j = 0; j < m; ++j) cout << grid[i][j];
        }
    }

    return 0;
}