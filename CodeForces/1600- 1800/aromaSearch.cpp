#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll maxn = (1ll << 62) - 1;
ll x0, yy, ax, ay, bx, by, xs, ys, t;
vector<ll> x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x0 >> yy >> ax >> ay >> bx >> by >> xs >> ys >> t;
    x.push_back(x0);
    y.push_back(yy);

    while((maxn - bx)/ax >= x.back() && (maxn - by)/ay >= y.back()) {
        x.push_back(x.back() * ax + bx);
        y.push_back(y.back() * ay + by);
    }

    ll ans = 0;
    for(ll i = 0; i < (ll)x.size(); ++i) {
        for(ll j = i; j < (ll)x.size(); ++j) {
            ll dist = x[j] - x[i] + y[j] - y[i];
            if(t - abs(x[j] - xs) - abs(y[j] - ys) >= dist || t - abs(x[i] - xs) - abs(y[i] - ys) >= dist) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}