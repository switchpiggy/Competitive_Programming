#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y, xx, yy, n;
vector<pair<pair<ll, ll>, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> xx >> yy >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll a = (x * v[i].first.first) + (y * v[i].first.second) + v[i].second;
        ll b = (xx * v[i].first.first) + (yy * v[i].first.second) + v[i].second;

        if((a > 0 && b < 0) || (a < 0 && b > 0)) ans++;
    }

    cout << ans << '\n';
    return 0;
}