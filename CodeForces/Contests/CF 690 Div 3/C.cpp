#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x;
        ll ans = LLONG_MAX;
        for(ll i = 0; i < (1 << 9); ++i) {
            ll cur = 0;
            ll res = 0;
            for(ll j = 1; j <= 9; ++j) {
                ll k = j - 1;
                if((1 << k) & i) {
                    cur += j;
                    res = res * 10 + j;
                }
            }

            if(cur == x) ans = min(ans, res);
        }

        if(ans == LLONG_MAX) ans = -1;
        cout << ans << '\n';
    }
}