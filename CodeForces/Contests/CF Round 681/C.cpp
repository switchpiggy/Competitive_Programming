#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[200007], b[200007];
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.first == y.first) return x.second < y.second;
    return x.first > y.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) cin >> b[i];

        for(ll i = 0; i < n; ++i) {
            v.push_back({a[i], b[i]});
        }

        sort(v.begin(), v.end(), cmp);

        ll sum = 0;
        for(ll i = 0; i < (ll)v.size(); ++i) {
            if(sum + v[i].second <= v[i].first) {
                sum += v[i].second;
                v[i].first = 0;
            } else break;
        }

        ll ans = sum;
        for(ll i = 0; i < (ll)v.size(); ++i) ans = max(ans, v[i].first);

        cout << ans << '\n';
    }

    return 0;
}