#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll l = 0, r = 0;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        l += a;
        r += b;
        v.push_back({a, b});
    }

    ll ans = abs(l - r), ind = -1;
    for(ll i = 0; i < n; ++i) {
        if(abs((l + v[i].second - v[i].first) - (r - v[i].second + v[i].first)) > ans) {
            ans = abs((l + v[i].second - v[i].first) - (r - v[i].second + v[i].first));
            ind = i;
        }
    }

    cout << ind + 1 << '\n';
    return 0;
}