#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, x, a[200007], pref[200007], suf[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> x;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll cur = 1;
    while(k--) cur *= x;

    pref[0] = a[0];
    for(ll i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] | a[i];
    }

    suf[n - 1] = a[n - 1];
    for(ll i = n - 2; i >= 0; --i) {
        suf[i] = suf[i + 1] | a[i];
    }

    ll ans = INT_MIN;
    for(ll i = 1; i < n - 1; ++i) {
        ans = max(ans, (cur * a[i]) | suf[i + 1] | pref[i - 1]);
    }

    ans = max(ans, (cur * a[0]) | suf[1]);
    ans = max(ans, (cur * a[n - 1]) | pref[n - 2]);
    cout << ans << '\n';
    return 0;
}