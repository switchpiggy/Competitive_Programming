#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[200007];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a[i];
    }

    sort(a, a + m);
    if(a[0] > 1) v.push_back({1, a[0] - 1});
    //for(ll i = 0; i < m; ++i) cout << a[i] << ' ';

    for(ll i = 1; i < m; ++i) {
        if(a[i] > a[i - 1] + 1) v.push_back({a[i - 1] + 1, a[i] - 1});
    }

    if(a[m - 1] < n) v.push_back({a[m - 1] + 1, n});

    ll mins = LONG_LONG_MAX;
    for(ll i = 0; i < (ll)v.size(); ++i) mins = min(mins, v[i].second - v[i].first + 1);

    ll ans = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) ans += (v[i].second - v[i].first + mins)/mins;
    //for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i].first << ' ' << v[i].second << ' ' << ' ';

    cout << ans << '\n';
    //cout << mins << '\n';
    return 0;
}