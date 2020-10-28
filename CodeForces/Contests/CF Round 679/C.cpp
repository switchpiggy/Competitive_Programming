#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[7], b[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(ll i = 0; i < 6; ++i) cin >> a[i];
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> b[i];

    sort(a, a + 6);
    sort(b + 1, b + 1 + n);

    ll ans = INT_MAX;
    for(ll i = 0; i < 6; ++i) {
        ll maxn = b[1] - a[i], minn = b[1] - a[i];

        ans = min(ans, maxn - minn);
    }

    cout << ans << '\n';

    return 0;
}