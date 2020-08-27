#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n, m;

int main() {
    scanf("%lld", &q);

    while(q--) {

        scanf("%lld %lld", &n, &m);

        vector<ll> rows(n);
        vector<ll> cols(m);
        vector<string> grid(n);

        for(ll i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                if(grid[i][j] == '.') {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        ll ans = n + m;

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                ans = min(ans, rows[i] + cols[j] - (grid[i][j] == '.'));
            }
        }

        printf("%lld\n", ans);
    }
}