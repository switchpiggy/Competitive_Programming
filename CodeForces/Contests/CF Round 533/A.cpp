#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = INT_MAX, ans2 = 1;
    for(ll t = 1; t <= 100; ++t) {
        ll res = 0;
        for(ll i = 0; i < n; ++i) {
            if(abs(t - a[i]) <= 1) continue;
            res += abs(t - a[i]) - 1;
        }

        if(res < ans) {
            ans2 = t;
            ans = res;
        }
    }

    cout << ans2 << ' ' << ans << '\n';
    return 0;
}