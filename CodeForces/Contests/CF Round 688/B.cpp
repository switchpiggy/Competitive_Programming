#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            if(i) ans += abs(a[i] - a[i - 1]);
        }

        ll res = max(abs(a[n - 1] - a[n - 2]), abs(a[1] - a[0]));
        for(ll i = 1; i < n - 1; ++i) {
            res = max(res, abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[i - 1]));
        }

        cout << ans - res << '\n';
    }

    return 0;
}