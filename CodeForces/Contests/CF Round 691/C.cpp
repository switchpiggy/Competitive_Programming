#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], b[200007], m;

ll _gcd(ll x, ll y) {
    if(x == 0) return y;
    if(y == 0) return x;
    return __gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < m; ++i) cin >> b[i];
    sort(a, a + n);

    ll gcd = 0;
    for(ll i = 1; i < n; ++i) gcd = _gcd(gcd, a[i] - a[0]);

    for(ll i = 0; i < m; ++i) {
        cout << _gcd(b[i] + a[0], gcd) << ' ';
    }

    return 0;
}