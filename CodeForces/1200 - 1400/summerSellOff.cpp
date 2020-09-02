#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, f;
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return min(x.first, x.second - x.first) > min(y.first, y.second - y.first);
}

int main() {
    cin >> n >> f;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), cmp);

    ll ans = 0;
    for(ll i = 0; i < v.size() && i < f; ++i) {
        ans += min(2 * v[i].first, v[i].second);
    }

    for(ll i = f; i < v.size(); ++i) {
        ans += min(v[i].first, v[i].second);
    }

    cout << ans << endl;
    return 0;
}