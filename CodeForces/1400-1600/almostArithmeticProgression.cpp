#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    if(n <= 2) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = INT_MAX;

    for(ll i = -1; i <= 1; ++i) {
        for(ll j = -1; j <= 1; ++j) {
            ll d = (a[1] + j) - (a[0] + i);
            bool ok = 1;

            ll cur = a[0] + i + 2 * d;
            for(ll k = 2; k < n; ++k) {
                if(abs(a[k] - cur) > 1) {
                    ok = 0;
                    break;
                }

                cur += d;
            }

            if(ok) {
                ll cnt = abs(i) + abs(j), cur2 = a[0] + i + 2 * d;
                for(ll k = 2; k < n; ++k) {
                    cnt += abs(a[k] - cur2);
                    cur2 += d;
                }

                //cout << cnt << '\n';
                ans = min(ans, cnt);
            }
        }
    }

    if(ans == INT_MAX) ans = -1; 
    cout << ans << '\n';
    return 0;
}