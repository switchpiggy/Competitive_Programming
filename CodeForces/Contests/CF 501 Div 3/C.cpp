#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
vector<pair<ll, ll>> v;

bool comp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.first - x.second > y.first - y.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
        sum += a;
    }

    if(sum <= m) {
        cout << 0 << '\n';
        return 0;
    }

    sort(v.begin(), v.end(), comp);

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ans++;
        sum -= v[i].first;
        sum += v[i].second;
        if(sum <= m) break;
    }

    if(sum <= m) cout << ans << '\n';
    else cout << "-1\n";
    return 0;
}