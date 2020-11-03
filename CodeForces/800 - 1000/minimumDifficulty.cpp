#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    ll ans = INT_MAX;
    for(ll i = 2; i < n; ++i) {
        ll res = INT_MIN;
        for(ll j = 1; j <= n; ++j) {
            if(j == i) continue;
            if(j == i - 1) res = max(res, a[j + 2] - a[j]);
            else res = max(res, a[j + 1] - a[j]);
        }

        ans = min(ans, res);
    }

    cout << ans << '\n';
    return 0;
}