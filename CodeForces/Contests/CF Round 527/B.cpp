#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);

    ll ans = 0;
    for(ll i = 0; i < n; i += 2) {
        ans += a[i + 1] - a[i];
    }

    cout << ans << '\n';
    return 0;
}