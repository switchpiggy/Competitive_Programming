#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

const ll MOD = 1000000007;

ll factorial(ll x) {
    ll ans = 1;
    for(ll i = 2; i <= x; ++i) {
        ans *= i;
        ans %= MOD;
    }

    return ans;
}

ll pow2(ll x) {
    
    ll ans = 1;
    while(x--) {
        ans *= 2;
        ans %= MOD;
    }

    return ans;
}

int main() {
    cin >> n;

    cout << (factorial(n) - pow2(n - 1) + MOD)%MOD << endl;
    return 0;
}