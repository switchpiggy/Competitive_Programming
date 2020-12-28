#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, r[107], b[107], m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> r[i];
        cin >> m;
        for(ll i = 1; i <= m; ++i) cin >> b[i];
        //ll ans = 0;

        for(ll i = 1; i <= n; ++i) r[i] += r[i - 1];
        for(ll i = 1; i <= m; ++i) b[i] += b[i - 1];

        ll ans = 0;
        for(ll i = 1; i <= n; ++i) {
            ans = max(ans, r[i]);
        }

        ll ans2 = 0;
        for(ll i = 1; i <= m; ++i) ans2 = max(ans2, b[i]);

        cout << ans + ans2 << '\n';
    }

    return 0;
}