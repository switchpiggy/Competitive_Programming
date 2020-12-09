#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
ll n, k, l, r;
//map<ll, ll> m;
vector<pair<ll, ll>> v;
vector<pair<ll, ll>> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> l >> r;
        v.push_back({l, -1});
        v.push_back({r, +1});
        //m[l] = r;
    }
    //for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i].first << ' ' << v[i].second << '\n';

    sort(v.begin(), v.end());
    ll prev = -1, cur = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        cur -= v[i].second;
        if(cur + v[i].second < k && cur >= k) {
            prev = v[i].first;
        }
        if(cur + v[i].second >= k && cur < k) {
            res.push_back({prev, v[i].first});
            prev = -1;
        }
    }

    cout << (ll)res.size() << '\n';
    for(ll i = 0; i < (ll)res.size(); ++i) cout << res[i].first << ' ' << res[i].second << '\n';
    return 0;
}