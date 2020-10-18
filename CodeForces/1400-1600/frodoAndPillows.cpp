#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k;

ll calc(ll x, ll y) {
    if(y > x - 1) return ((x - 1) * x)/2 + (y - (x - 1));
    return ((x - 1 + x - y) * y + 1)/2;
}

bool check(ll x) {
    if(calc(x, k - 1) + calc(x, n - k) + x <= m) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    ll l = 1, r = m + 1;

    ll ans = 1;
    while(l < r) {
        ll a = (l + r)/2;
        if(check(a)) {
            l = a + 1;
            ans = a;
        } else r = a;
    }

    cout << ans << '\n';
    return 0;
}