#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, a;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> a;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, a + b});
    }

    v.push_back({0, 0});
    v.push_back({l, l});
    sort(v.begin(), v.end());

    ll ans = 0;
    for(ll i = 0; i < (ll)v.size() - 1; ++i) {
        if(v[i].second < v[i + 1].first) ans += (v[i + 1].first - v[i].second)/a;
    }

    cout << ans << '\n';
    return 0;
}