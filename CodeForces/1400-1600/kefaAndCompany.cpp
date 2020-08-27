#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, d, x, y;
vector<pair<ll, ll>> v;

int main() {
    cin >> n >> d;
    v.push_back(make_pair(0, 0));
    for(ll i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());
    ll ans = INT_MIN;

    for(ll i = 1; i <= n; ++i) v[i].second += v[i - 1].second;

    for(ll i = 1; i <= n; ++i) {
        ll cur = v[i].first + d;
        auto j = lower_bound(v.begin(), v.end(), make_pair(cur, 0ll));
        if(j == v.end()) {
            ans = max(v[n].second - v[i - 1].second, ans);
            continue;
        }

        while(j->first >= cur) j--;

        ans = max(ans, j->second - v[i - 1].second);
    } 

    cout << ans << endl;

    return 0;
}