#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k[300007], c[300007], t, pk[300007], pc[300007];

bool check(ll x) {
    for(ll i = 0; i < x; ++i) if(k[i] < x - i) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 0; i < n; ++i) {
            cin >> k[i];
        }
        for(ll j = 0; j < m; ++j) {
            cin >> c[j];
            pc[j] = c[j];
        }

        sort(k, k + n, greater<ll>());

        pk[0] = c[k[0] - 1];
        for(ll i = 1; i < n; ++i) pk[i] = pk[i - 1] + c[k[i] - 1];
        for(ll i = 1; i < m; ++i) pc[i] += pc[i - 1];

        ll l = 0, r = n + 1, ans = 1;
        while(l < r) {
            ll mid = (l + r)/2;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid;
        }

        //for(ll i = 0; i < n; ++i) cout << pk[i] << ' ';

        ll res = pk[n - 1];
        //cout << res << '\n';
        for(ll i = 0; i < ans && i < m; ++i) {
            res = min(res, pc[i] + pk[n - 1] - pk[i]);
        }

        cout << res << '\n';
    }

    return 0;
}