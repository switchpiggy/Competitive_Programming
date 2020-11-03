#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
char a[30][30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < m; ++j) cin >> a[i][j];

    ll ans = 1;

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            for(ll k = i; k < n; ++k) {
                for(ll l = j; l < m; ++l) {
                    bool ok = 1;
                    for(ll c = i; c <= k; ++c) {
                        for(ll d = j; d <= l; ++d) {
                            if(a[c][d] == '1') {
                                ok = 0;
                                break;
                            }
                        }
                    }

                    if(ok == 1) {
                        ans = max(ans, 2 * (l - j + 1) + 2 * (k - i + 1));
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}