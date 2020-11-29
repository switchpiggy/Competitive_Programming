#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

ll sigDig(ll x) {
    return (ll)log2(x) + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = LONG_LONG_MAX;
    for(ll i = 0; i < n - 1; ++i) {
            ll cnt = 0, cur = a[i];
            bool ok = 0;
            for(ll j = i - 1; j >= 0; --j) {
                if(sigDig(a[j]) == sigDig(a[j + 1])) break;
                cnt++;
                cur ^= a[j];
                if(cur > a[i + 1]) {
                    ok = 1;
                    break;
                }
            }

            if(ok) ans = min(ans, cnt);
    }

    for(ll i = n - 1; i >= 1; --i) {
        ll cur = a[i], cnt = 0;
        bool ok = 0;
        for(ll j = i + 1; j < n; ++j) {
            if(sigDig(a[j]) > sigDig(a[j - 1])) break;
            cnt++;
            cur ^= a[j];

            if(cur < a[i - 1]) {
                ok = 1;
                break;
            }
        }

        if(ok) ans = min(ans, cnt);
    }

    if(ans == LONG_LONG_MAX) ans = -1;
    cout << ans << '\n';
    return 0;
}