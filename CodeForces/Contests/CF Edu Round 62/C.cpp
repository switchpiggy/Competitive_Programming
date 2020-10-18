#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        ll t, b;
        cin >> t >> b;
        v.push_back({t, b});
    }

    sort(v.begin(), v.end(), cmp);

    for(ll i = 1; i < n; ++i) {
        v[i].first += v[i - 1].first;
    }

    ll ans = 0;
    for(ll i = 0; i < k; ++i) {
        ans = max(ans, v[i].second * v[i].first);
    }

    for(ll i = k; i < n; ++i) {
        ans = max(ans, v[i].second * (v[i].first - v[i - k].first));
    }

    cout << ans << '\n';
    return 0;
}