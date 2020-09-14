#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l, r, k;

ll logk(ll x, ll y) {
    ll ans = 0;
    while(x >= y) {
        x /= y;
        ans++;
    }

    return ans;
}

ll fastpow(ll x, ll y) {
    //x to the power of y
    if(y == 0) return 1;

    if(y%2 == 0) {
        return fastpow(x, y/2) * fastpow(x, y/2);
    }

    return x * fastpow(x, y/2) * fastpow(x, y/2);
}

int main() {
    cin >> l >> r >> k;
    ll a = logk(l, k), b = logk(r, k);

    if(fastpow(k, a) < l) a++;

    if(a > b) {
        cout << -1 << '\n';
        return 0;
    }

    ll cur = fastpow(k, a);
    for(ll i = a; i <= b; ++i) {
        cout << cur << ' ';
        cur *= k;
    }

    return 0;
}

