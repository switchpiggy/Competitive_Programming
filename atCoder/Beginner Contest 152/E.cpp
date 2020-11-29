#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[10007];
const ll MOD = 1000000007;

ll lcd(ll x, ll y) {
    return (x * y)/__gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll lcm = 1;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        lcm = lcd(lcm, a[i]);
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) ans = (ans + lcm/a[i])%MOD;

    cout << ans << '\n';
    return 0;
}