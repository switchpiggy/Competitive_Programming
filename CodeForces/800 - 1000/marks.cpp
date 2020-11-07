#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
char grid[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> grid[i][j];
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            bool ok = 1;
            for(ll k = 0; k < n; ++k) {
                if(grid[k][j] - '0' > grid[i][j] - '0') {
                    ok = 0;
                    break;
                } 
            }

            if(ok) {
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}