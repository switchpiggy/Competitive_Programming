#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[3007], occ[9003007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        memset(occ, 0, sizeof(occ[0]) * (n * n + n + 1));

        ll ans = 0;
        for(ll i = n - 3; i > 0; --i) {
            for(ll j = i + 2; j < n; ++j) {
                occ[a[i + 1] * n + a[j]]++;
            }

            for(ll j = 0; j < i; ++j) {
                ans += occ[a[j] * n + a[i]];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}