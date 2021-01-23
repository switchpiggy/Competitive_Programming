#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll a[100007], k;
const ll MOD = 1e9 + 7;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2) return ((recurse * recurse)%MOD * x)%MOD;
    return (recurse * recurse)%MOD;
}

ll inv(ll x) {
    return fastpow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    ll ans = 2, n = 1;
    for(ll i = 0; i < k; ++i) {
        cin >> a[i];
        n *= (a[i]%2);
        ans = (fastpow(ans, a[i]))%MOD;
    }

    if(n%2 == 0) cout << (((ans * inv(2))%MOD + 1 + MOD)%MOD * inv(3))%MOD << '/' << (ans * inv(2))%MOD << '\n';
    else cout << (((ans * inv(2))%MOD - 1 + MOD)%MOD * inv(3))%MOD << '/' << (ans * inv(2))%MOD << '\n';

    //cout << ans - 1 << '/' << ans << '\n';
    return 0;
}