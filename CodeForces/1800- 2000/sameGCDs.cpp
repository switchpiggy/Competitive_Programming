#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
ll t, a, m;

ll phi(ll x) {
    ll res = x;
    for(ll i = 2; i * i <= x; ++i) {
        if(x%i == 0) {
            while(x%i == 0) x /= i;
            res -= res/i;
        }
    }

    if(x > 1) res -= res/x;

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> m;
        cout << phi(m/__gcd(a, m)) << '\n';
    }

    return 0;
}