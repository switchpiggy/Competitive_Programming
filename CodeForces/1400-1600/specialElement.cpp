#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[8007], occ[8007];

int main() {
    cin >> t;
    while(t--) {
        memset(occ, 0, sizeof(occ));
        
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            occ[a[i]]++;
        }

        ll ans = 0;

        for(ll l = 0; l < n; ++l) {

            ll cur = 0;
            for(ll r = l; r < n; ++r) {
                cur += a[r];
                if(l == r) continue;
                if(cur <= n) {
                    ans += occ[cur];
                    occ[cur] = 0;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}