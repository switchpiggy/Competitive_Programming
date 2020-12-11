#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, pref[507][507];
char grid[507][507];

ll solve(ll i, ll j, ll k) {
    if(j < 0 || k >= m || i >= n) return 0;

    if(pref[i][k] - (j ? pref[i][j - 1] : 0) == k - j + 1) return 1 + solve(i + 1, j - 1, k + 1); 
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(pref, 0, sizeof(pref));
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if(j) pref[i][j] = pref[i][j - 1];
                pref[i][j] += (grid[i][j] == '*');
            }
        }

        ll ans = 0;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                if(grid[i][j]) ans += solve(i, j, j);
            }
        }

        cout << ans << '\n';
    }
}