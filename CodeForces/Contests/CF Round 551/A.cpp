#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t, ans[107];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    for(ll i = 0; i < n; ++i) {
        ll s, d;
        cin >> s >> d;
        v.push_back({s, d});
    }

    for(ll i = 0; i < n; ++i) {
        ll cur = v[i].first;
        while(cur < t) {
            cur += v[i].second;
        }

        ans[i] = cur;
    }

    ll res = 0;
    for(ll i = 0; i < n; ++i) {
        if(ans[i] - t < ans[res] - t) res = i;
    }

    cout << res + 1 << '\n';
    return 0;
}