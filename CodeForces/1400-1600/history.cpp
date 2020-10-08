#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    pair<ll, ll> prev = v[0];

    ll ans = 0;
    for(ll i = 1; i < n; ++i) {
        if(prev.first < v[i].first && prev.second > v[i].second) {
            ans++;
        } else prev = v[i];
    }

    cout << ans << '\n';
    return 0;
}