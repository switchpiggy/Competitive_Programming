#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll b, q, l, m, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> b >> q >> l >> m;
    for(ll i = 0; i < m; ++i) cin >> a[i];
    sort(a, a + m);

    if(abs(b) > l) {
        cout << "0\n";
        return 0;
    }

    if(b == 0) {
        ll i = lower_bound(a, a + m, 0) - a;
        if(i < m && a[i] == 0) cout << "0\n";
        else cout << "inf\n";
        return 0;
    } else if(q == 0) {
        ll i = lower_bound(a, a + m, 0) - a, j = lower_bound(a, a + m, b) - a;
        if(i < m && a[i] == 0 && j < m && a[j] == b) cout << "0\n";
        else if(i < m && a[i] == 0) cout << "1\n";
        else cout << "inf\n";
        return 0;
    } else if(q == 1) {
        ll i = lower_bound(a, a + m, b) - a;
        if(i < m && a[i] == b) cout << "0\n";
        else cout << "inf\n";
        return 0;
    } else if(q == -1) {
        ll i = lower_bound(a, a + m, b) - a, j = lower_bound(a, a + m, -b) - a;
        ll res = 0;
        if(i < m && a[i] == b) res++;
        if(j < m && a[j] == -b) res++;
        if(res != 2) cout << "inf\n";
        else cout << "0\n";
        return 0;
    }

    ll ans = 0;
    while(abs(b) <= l) {
        ll i = lower_bound(a, a + m, b) - a;
        if(!(i < m && a[i] == b)) ans++;
        b *= q;
    }

    cout << ans << '\n';
    return 0;
}