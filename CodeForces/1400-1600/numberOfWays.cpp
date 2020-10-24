#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[500007], suff[500007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if(sum%3 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    ll cur = 0;
    for(ll i = n - 1; i >= 0; --i) {
        cur += a[i];
        if(cur == sum/3) suff[i] = 1;
    }

    for(ll i = 1; i < n; ++i) suff[i] += suff[i - 1];

    ll ans = 0, c = 0;
    for(ll i = 0; i < n - 2; ++i) {
        c += a[i];
        if(c == sum/3) ans += (suff[n - 1] - suff[i + 1]);
    }

    cout << ans << '\n';
    return 0;
}