#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

ll largestFactor(ll x) {
    ll ans = 1;
    for(ll i = 2; i * i <= x; ++i) {
        if(x%i == 0) {
            ans = max(ans, i);
            if(x%(x/i) == 0) ans = max(ans, x/i);
        }
    }

    return ans;
}

ll fastPow(ll x) {
    ll ans = 1;
    while(x--) {
        ans *= 2;
    }

    return ans;
}

ll gcd(ll x, ll y) {
    if(!x) return y;
    if(!y) return x;
    return __gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        ll x = log2(n) + 1;

        ll y = fastPow(x) - 1;

        if(y == n) {
            y = largestFactor(n);
            cout << gcd(n^y, n&y) << '\n';
        } else {
            y ^= n;
            cout << gcd(n^y, n&y) << '\n';
        }
    }

    return 0;
}