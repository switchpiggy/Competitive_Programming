#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
vector<pair<ll, ll>> v;

bool check(pair<ll, ll> x, pair<ll ,ll> y) {
    if(x.first + y.first <= a && max(x.second, y.second) <= b) return 1;
    if(x.first + y.first <= b && max(x.second, y.second) <= a) return 1;
    if(x.first + y.second <= a && max(x.second, y.first) <= b) return 1;
    if(x.first + y.second <= b && max(x.second, y.first) <= a) return 1;
    if(x.second + y.first <= a && max(x.first, y.second) <= b) return 1;
    if(x.second + y.first <= b && max(x.first, y.second) <= a) return 1;
    if(x.second + y.second <= a && max(x.first, y.first) <= b) return 1;
    if(x.second + y.second <= b && max(x.first, y.first) <= a) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    for(ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(i == j) continue;
            if(check(v[i], v[j])) ans = max(ans, v[i].first * v[i].second + v[j].first * v[j].second);
        }
    }

    cout << ans << '\n';
    return 0;
}