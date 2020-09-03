#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
const ll MOD = 1e9 + 7;

ll pow27(ll x) {
    ll ans = 1;
    while(x--) {
        ans *= 27;
        ans %= MOD;
    }

    return (ans + MOD)%MOD;
}

ll pow7(ll x) {
    ll ans = 1;
    while(x--) {
        ans *=7;
        ans %= MOD;
    }

    return (ans + MOD)%MOD;
}

int main() {
    cin >> n;
    cout << (pow27(n) - pow7(n) + MOD)%MOD << endl;
    return 0;
}