#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, w[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < 2 * n; ++i) cin >> w[i];

    sort(w, w + 2 * n);

    ll ans = INT_MAX;
    for(ll i = 0; i < 2 * n; ++i) {
        for(ll j = 0; j < 2 * n; ++j) {
            ll res = 0;
            vector<ll> v;
            for(ll k = 0; k < 2 * n; ++k) {
                if(k == i || k == j) continue;
                v.push_back(w[k]);
            }

            for(ll k = 0; k < 2 * n - 2; k += 2) {
                res += abs(v[k + 1] - v[k]);
            }

            ans = min(ans, res);
        }
    }

    cout << ans << '\n';
    return 0;
}