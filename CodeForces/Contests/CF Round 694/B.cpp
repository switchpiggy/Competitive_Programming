#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x;
vector<pair<ll, ll>> v;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2) return (recurse * recurse * x);
    return recurse * recurse;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> x;
        for(ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            v.push_back({a, 1});
        }

        ll sum = 0;// i = 0;
        for(ll i = 0; i < (ll)v.size(); ++i) {
            if(v[i].first%x == 0) {
                v.push_back({v[i].first/x, v[i].second * x});
            } else {
                break;
            }
        }

        for(ll i = 0; i < (ll)v.size(); ++i) sum += v[i].first * v[i].second;

        cout << sum << '\n';
    }

    return 0;
}