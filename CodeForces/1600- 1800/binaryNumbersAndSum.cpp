#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, pref[200007];
string s, t;
const ll MOD = 998244353;

ll fastpow(ll x, ll y) {
    if(y == 0) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2) return ((recurse * recurse)%MOD * x)%MOD;
    return (recurse * recurse)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    for(ll i = 0; i < (ll)t.length(); ++i) {
        pref[i] = (t[i] - '0');
        if(i) pref[i] += pref[i - 1];
    }  

    ll ans = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(i >= (ll)t.length()) break;
        if(s[i] == '0') continue;
        ans = (ans + ((fastpow(2, i))%MOD * (pref[(ll)t.length() - 1] - (i ? pref[i - 1] : 0))%MOD)%MOD)%MOD;
    }

    cout << ans << '\n';
    return 0;
} 