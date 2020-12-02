#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, x, y, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> x >> y;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    bool ok = 0, ok2 = 0;
    for(ll i = 0; i < n; ++i) {
        ll j = lower_bound(a, a + n, a[i] + x) - a, k = lower_bound(a, a + n, a[i] + y) - a;
        if(j < n && a[j] == a[i] + x) ok = 1;
        if(k < n && a[k] == a[i] + y) ok2 = 1;
    }

    if(ok && ok2) {
        cout << 0 << '\n';
    } else if(ok) cout << 1 << '\n' << y << '\n';
    else if(ok2) cout << 1 << '\n' << x << '\n';
    else {
        for(ll i = 0; i < n; ++i) {
            ll j = lower_bound(a, a + n, a[i] + x - y) - a, k = lower_bound(a, a + n, a[i] + x + y) - a;
            if(j < n && a[j] == a[i] + x - y && a[i] + x <= l) {
                cout << 1 << '\n' << a[i] + x << '\n';
                return 0;
            }

            if(k < n && a[k] == a[i] + x + y && a[i] + x + y <= l) {
                cout << 1 << '\n' << a[i] + x << '\n';
                return 0;
            }

            j = lower_bound(a, a + n, a[i] - x - y) - a, k = lower_bound(a, a + n, a[i] - x + y) - a;
            if(j < n && a[i] - x - y >= 0 && a[j] == a[i] - x - y) {
                cout << 1 << '\n' << a[i] - x << '\n';
                return 0;
            }

            if(k < n && a[i] - x >= 0 && a[k] == a[i] - x + y) {
                cout << 1 << '\n' << a[i] - x << '\n';
                return 0;
            }
        }

        cout << "2\n" << x << ' ' << y << '\n';
    }
    return 0;
}