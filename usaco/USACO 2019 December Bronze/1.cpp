#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k, n, a[27][27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    cin >> k >> n;
    for(ll i = 0; i < k; ++i) {
        for(ll j = 0; j < n; ++j) cin >> a[i][j];
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(i == j) continue;
            bool ok = 1;
            for(ll q = 0; q < k; ++q) {
                ll pos1, pos2;
                for(ll p = 0; p < n; ++p) {
                    if(a[q][p] == i) pos1 = p;
                    if(a[q][p] == j) pos2 = p;
                }

                if(pos1 > pos2) {
                    ok = 0;
                    break;
                }
            }

            ans += ok;
        }
    }

    cout << ans << '\n';
    return 0;
}