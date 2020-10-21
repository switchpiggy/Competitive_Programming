#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);
    a[n] = INT_MAX;

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll up = upper_bound(a, a + n + 1, a[i] + 5) - a;
        //cout << up << ' ' << i << '\n';
        ans = max(ans, up - i);
    }

        cout << ans << '\n';
    return 0;
}