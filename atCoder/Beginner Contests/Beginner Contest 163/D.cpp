#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[200007];
const ll MOD = 1000000007;

int main() {
    cin >> n >> k;
    ll ans = 0;

    for(ll i = 1; i <= n + 1; ++i) {
        a[i] = i;
        a[i] += a[i - 1];
    }

    for(ll m = k; m <= n + 1; ++m) {
        ll maxs = a[n] - a[max(0ll, n - m)], mins = a[m - 1];
        ans += maxs - mins + 1;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}