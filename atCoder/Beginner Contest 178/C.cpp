
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

const ll MOD = 1e9 + 7;

ll fastpow(ll x, ll y) {
    ll ans = 1;
    while(y--) {
        ans *= x;
        ans %= MOD;
    }

    return (ans%MOD + MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cout << ((fastpow(10, n) - 2 * fastpow(9, n) + fastpow(8, n))%MOD + MOD)%MOD << '\n';

    return 0;
}