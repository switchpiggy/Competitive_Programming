#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[2000007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    sort(a, a + n);

    ll ans = 0;

    for(ll i = 0; i < n; ++i) {
        ll l = lower_bound(a, a + n, (a[i] + 1)/2) - a;
        ans += i - l;
    }

    cout << ans << '\n';
    return 0;
}