#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l, r, x, y;
set<pair<ll, ll>> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r >> x >> y;
    if(y%x != 0) {
        cout << "0\n";
        return 0;
    }
    ll ans = 0;
    for(ll i = 1; i * i <= y/x; ++i) {
        if(i >= (l + x - 1)/x && i <= r/x && (y/x)/i >= (l + x - 1)/x && (y/x)/i <= r/x && (y/x)%i == 0 && __gcd(i, (y/x)/i) == 1) {
            ans++;
            if(i != (y/x)/i) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}