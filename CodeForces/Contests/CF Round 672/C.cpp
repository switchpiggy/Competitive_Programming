#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, q, a[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> q;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        ll res = 0;
        for(ll i = 0; i < n - 1; ++i) {
            if(a[i + 1] < a[i]) res += a[i] - a[i + 1];
        }

        if(a[n - 1] < a[n - 2]) {
            res += a[n - 1];
        }

        ll maxn = 0;
        for(ll i = n - 1; i >= 0; --i) {
            if(i > 0 && a[i] < a[i - 1]) break;
            maxn = max(maxn, a[i]);
        }

        res += maxn;
        
        cout << res << '\n';
    }

    return 0;
}