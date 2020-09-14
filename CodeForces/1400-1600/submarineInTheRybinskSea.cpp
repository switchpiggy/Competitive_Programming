#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];
const ll MOD = 998244353;

ll fastpow(ll x, ll y) {
    ll ans = 1;
    while(y--) {
        ans *= x;
        ans %= MOD;
    }

    return (ans%MOD + MOD)%MOD;
}

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;

    for(ll i = 0; i < n; ++i) {
        string s = to_string(a[i]);
        for(ll j = 0; j < s.length(); ++j) {
            ll p = fastpow(10, 2 * ((ll)s.length() - j) - 2);
            ans += (s[j] - '0') * n * (11 * p);
            ans = (ans%MOD + MOD)%MOD;
        } 
    }

    cout << ans << '\n';
    return 0;
}