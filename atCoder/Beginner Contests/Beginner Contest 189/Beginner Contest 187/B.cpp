#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> v;

bool slope(ll a, ll b, ll c, ll d) {
    if(abs(b - d) <= abs(a - c)) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            ans += slope(v[i].first, v[i].second, v[j].first, v[j].second);
        }
    }

    cout << ans << '\n';
    return 0;
}