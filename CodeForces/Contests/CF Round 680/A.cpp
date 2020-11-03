#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, a[57], b[57];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> x;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) cin >> b[i];

        sort(a, a + n);
        sort(b, b + n, greater<ll>());

        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i] + b[i] > x) {
                ok = 1;
                break;
            }
        }

        if(ok) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}