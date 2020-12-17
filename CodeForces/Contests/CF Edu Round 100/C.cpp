#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007], b[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i] >> b[i];
        a[n] = LLONG_MAX, b[n] = 0;
        
        ll ans = 0, cur = 0, nxt = b[0];
        for(ll i = 0; i < n; ++i) {
            ll prev = cur;
            if(a[i + 1] - a[i] >= abs(nxt - cur)) {
                cur = nxt;
                nxt = b[i + 1];
            } else {
                if(nxt >= cur) cur += a[i + 1] - a[i];
                else cur -= a[i + 1] - a[i];
            }

            if((prev <= b[i] && b[i] <= cur) || (cur <= b[i] && b[i] <= prev)) {
                ans++;
            }
        }

        cout << ans << '\n';
    }
}