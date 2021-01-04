#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, cc, pref[107][107][11], a[107][107][11];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> cc;
    for(ll i = 0; i < n; ++i) {
        ll x, y, s;
        cin >> x >> y >> s;
        for(ll j = 0; j <= cc; ++j) a[x][y][j] += (s + j)%(cc + 1);
    }

    for(ll k = 0; k <= cc; ++k) {
        for(ll i = 1; i <= 100; ++i) {
            pref[i][1][k] = a[i][1][k] + pref[i - 1][1][k], pref[1][i][k] = a[1][i][k] + pref[1][i - 1][k];
        }
        for(ll i = 2; i <= 100; ++i) {
            for(ll j = 2; j <= 100; ++j) {
                pref[i][j][k] = a[i][j][k] + pref[i - 1][j][k] + pref[i][j - 1][k] - pref[i - 1][j - 1][k];
            }
        }
    }

    //sort(v.begin(), v.end());

    for(ll i = 0; i < q; ++i) {
        ll t, b, c, d, e;
        cin >> t >> b >> c >> d >> e;
        //cout << sum << ' ' << count << '\n';
        //cout << sum << ' ' << cc * count << '\n';
        ll m = t%(cc + 1);
        cout << pref[d][e][m] - pref[b - 1][e][m] - pref[d][c - 1][m] + pref[b - 1][c - 1][m] << '\n';
    }

    /*for(ll i = 1; i <= 10; ++i, cout << '\n') {
        for(ll j = 1; j <= 10; ++j) cout << a[i][j][cc] << ' ';
    }*/

    return 0;
}