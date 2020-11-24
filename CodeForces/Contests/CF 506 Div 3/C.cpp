#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, r;
vector<pair<ll, ll>> v;

ll calc() {
    ll maxl = 0, minR = LONG_LONG_MAX;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        maxl = max(maxl, v[i].first);
        minR = min(minR, v[i].second);
    }

    return max(0ll, minR - maxl);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll maxL = 0, minR = LONG_LONG_MAX;
    for(ll i = 0; i < n; ++i) {
        cin >> l >> r;
        v.push_back({l, r});
        minR = min(minR, r);
        maxL = max(maxL, l);
    }

    ll maxInd = -1, minInd = -1;
    for(ll i = 0; i < n; ++i) {
        if(v[i].first == maxL) {
            maxInd = i;
        }

        if(v[i].second == minR) {
            minInd = i;
        }
    }

    ll a = v[maxInd].first, b = v[maxInd].second;
    v[maxInd].first = 0, v[maxInd].second = LONG_LONG_MAX;
    ll ans = calc();
    v[maxInd].first = a, v[maxInd].second = b;
    a = v[minInd].first, b = v[minInd].second;
    v[minInd].first = 0, v[minInd].second = LONG_LONG_MAX;
    ans = max(ans, calc());

    cout << ans << '\n';
    return 0;
}