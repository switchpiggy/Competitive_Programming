#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], pref[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for(ll i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ans += pref[n] - pref[i] - a[i] * (n - i);
    }

    cout << ans << '\n';
    return 0;
}