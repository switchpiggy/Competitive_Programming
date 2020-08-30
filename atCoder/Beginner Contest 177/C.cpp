#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, pref[200007];

int main() {
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> pref[i];
    for(ll i = 1; i <= n; ++i) pref[i] += pref[i - 1];

    ll sum = pref[n];

    ll ans = 0;
    for(ll i = 1; i <= n - 1; ++i) {
        ans += ((pref[i] - pref[i - 1]) * (sum - pref[i]))%1000000007;
        ans %= 1000000007;
    }

    cout << ans << endl;
    return 0;
}