#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, a[107];

int main() {
    cin >> n >> l;

    ll maxn = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        maxn = max(a[i], maxn);
    }

    ll ans = 0;
    for(ll i = l; i <= maxn; ++i) {
        ll res = 0;
        for(ll j = 0; j < n; ++j) res += a[j]/i;

        ans = max(ans, res * i);
    }

    cout << ans << endl;
    return 0;
}