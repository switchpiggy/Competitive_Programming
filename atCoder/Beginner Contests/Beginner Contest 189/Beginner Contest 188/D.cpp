
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, c;
vector<pair<ll, ll>> event;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(ll i = 0; i < n; ++i) {
        ll a, b, cc;
        cin >> a >> b >> cc;
        event.push_back({a, cc});
        event.push_back({b + 1, -cc});
    }

    sort(event.begin(), event.end());
    event.push_back({event.back().first + 1, 0});

    ll ans = 0, cur = 0;
    for(ll i = 0; i < (ll)event.size() - 1; ++i) {
        cur += event[i].second;
        if(event[i + 1].first > event[i].first) {
            ans += min(cur, c) * (event[i + 1].first - event[i].first);
        }
    }

    cout << ans << '\n';
    return 0;
}