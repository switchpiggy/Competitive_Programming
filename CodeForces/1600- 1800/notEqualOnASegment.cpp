#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[200007], p[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) p[i] = -1;

    ll prev = -1;
    for(ll i = 1; i < n; ++i) {
        if(a[i] != a[i - 1]) {
            p[i] = i - 1;
            prev = i - 1;
        } else p[i] = prev;
    }

    for(ll i = 0; i < m; ++i) {
        ll l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        if(a[r] != x) cout << r + 1 << '\n';
        else if(p[r] >= l) cout << p[r] + 1 << '\n';
        else cout << "-1\n";
    }

    return 0;
}