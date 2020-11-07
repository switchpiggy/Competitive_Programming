#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    v.push_back({0, 0});

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        v.push_back({l, r});
        ans += r - l + 1;
    }

    sort(v.begin(), v.end());

    for(ll i = 1; i <= n; ++i) {
        if(v[i].first <= v[i - 1].second) continue;
        ans += (v[i].first - v[i - 1].second - 1)%x;
    }

    cout << ans << '\n';
    return 0;
}