#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[207];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = INT_MIN;
    for(ll i = 0; i < n; ++i) {
        for(ll j = i; j < n; ++j) {
            vector<ll> sum;
            ll res = 0;
            for(ll l = i; l <= j; ++l) {
                sum.push_back(a[l]);
                res += a[l];
            }

            sort(sum.begin(), sum.end());
            vector<ll> v;
            for(ll l = 0; l < i; ++l) v.push_back(a[l]);
            for(ll l = j + 1; l < n; ++l) v.push_back(a[l]);
            sort(v.begin(), v.end(), greater<ll>());

            ll cur = 0;
            for(ll l = 0; l < k && l < (ll)sum.size(); ++l) {
                if(cur < (ll)v.size() && v[cur] > sum[l]) {
                    res += v[cur] - sum[l];
                    cur++;
                }
            }

            ans = max(ans, res);
        }
    }

    cout << ans << '\n';
    return 0;
}