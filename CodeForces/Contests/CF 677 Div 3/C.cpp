#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> a[i];

        ll maxn = 0;
        for(ll i = 1; i <= n; ++i) maxn = max(maxn, a[i]);

        a[0] = a[n + 1] = INT_MAX;
        ll res = -1;
        for(ll i = 1; i <= n; ++i) {
            if(a[i] == maxn && (a[i] > a[i - 1] || a[i] > a[i + 1])) {
                res = i;
                break;
            }
        }

        cout << res << '\n';
    }

    return 0;
}