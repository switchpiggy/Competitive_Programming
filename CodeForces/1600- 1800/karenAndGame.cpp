#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, g[107][107], r[107], c[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> g[i][j];
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(g[i][j] == 0) {
                ll ans = 0;
                for(ll k = 0; k < m; ++k) {
                    c[k] = g[i][k];
                    ans += c[k];
                }
                for(ll k = 0; k < n; ++k) {
                    r[k] = g[k][j];
                    ans += r[k];
                }

                for(ll k = 0; k < n; ++k) {
                    for(ll kk = 0; kk < m; ++kk) {
                        if(g[k][kk] != r[k] + c[kk]) {
                            cout << "-1\n";
                            return 0;
                        }
                    }
                }

                cout << ans << '\n';
                for(ll k = 0; k < m; ++k) {
                    for(ll kk = 0; kk < c[k]; ++kk) cout << "col " << k + 1 << '\n';
                }

                for(ll k = 0; k < n; ++k) {
                    for(ll kk = 0; kk < r[k]; ++kk) cout << "row " << k + 1 << '\n';
                }

                return 0;
            }
        }
    }

    ll ans = 0;
    if(n <= m) {
        ll mins = 0;
        for(ll i = 0; i < m; ++i) if(g[0][mins] > g[0][i]) mins = i;
        r[0] = g[0][mins];

        for(ll i = 0; i < m; ++i) {
            c[i] = g[0][i] - r[0];
            ans += c[i];
        }
        for(ll i = 0; i < n; ++i) {
            r[i] = g[i][mins];
            ans += r[i];
        }

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                if(r[i] + c[j] != g[i][j]) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    } else {
        ll mins = 0;
        for(ll i = 0; i < n; ++i) if(g[mins][0] > g[i][0]) mins = i;
        c[0] = g[mins][0];

        for(ll i = 0; i < n; ++i) {
            r[i] = g[i][0] - c[0];
            ans += r[i];
        }
        for(ll i = 0; i < m; ++i) {
            c[i] = g[mins][i];
            ans += c[i];
        }

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                if(r[i] + c[j] != g[i][j]) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    cout << ans << '\n';
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < r[i]; ++j) cout << "row " << i + 1 << '\n';
    }

    for(ll i = 0; i < m; ++i) {
        for(ll j = 0; j < c[i]; ++j) cout << "col " << i + 1 << '\n';
    }

    return 0;
}