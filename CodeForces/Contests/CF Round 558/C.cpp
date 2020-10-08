#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> v;
map<pair<ll, ll>, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    vector<pair<ll, ll>> u;
    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            ll gcd = __gcd(v[j].second - v[i].second , v[j].first - v[i].first);
            u.push_back({(v[j].second - v[i].second)/gcd, (v[j].first - v[i].first)/gcd});
        }
    }

    ll ans = 0;
    for(ll i = 0; i < (ll)u.size(); ++i) {
        ans += occ[u[i]];
        occ[u[i]]++;
    }

    cout << n + ans << '\n';
    return 0;
}