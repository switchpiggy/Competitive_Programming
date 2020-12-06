#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, x, c[107];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> x;
    for(ll i = 0; i < n; ++i) cin >> c[i];
    ll cur = 0;
    for(ll i = 0; i < n; ++i) {
        if(i && c[i] != c[i - 1]) {
            v.push_back({c[i - 1], cur});
            cur = 1;
        } else cur++;
    }

    if(cur) v.push_back({c[n - 1], cur});

    ll ans = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        //cout << v[i].first << ' ' << v[i].second << '\n';
        ll l = i - 1, r = i + 1;
        if(v[i].first == x && v[i].second >= 2) {
            ll cur = v[i].second;
            while(l >= 0 && r < n) {
                if(v[l].first == v[r].first && v[l].second + v[r].second >= 3) {
                    cur += v[l].second + v[r].second;
                    l--;
                    r++;
                } else break;
            }

            ans = max(ans, cur);
        }
    }

    cout << ans << '\n';
    return 0;
}