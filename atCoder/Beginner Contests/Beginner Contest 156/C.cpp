#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> x[i];

    sort(x, x + n);

    ll ans = LONG_LONG_MAX;
    for(ll i = 0; i <= 100; ++i) {
        ll cur = 0;
        for(ll j = 0; j < n; ++j) {
            cur += abs(x[j] - i) * abs(x[j] - i);
        }

        ans = min(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}