#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[200007], occ[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i <= n; ++i) occ[i] = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            occ[a[i]]++;
        }

        ll ans = 0;
        for(ll i = 1; i <= n; ++i) {
            if(!occ[i]) continue;
            if(occ[i] >= 3) ans += (occ[i] * (occ[i] - 1)  * (occ[i] - 2))/6;
            ans += (occ[i] * (occ[i] - 1))/2 * (occ[i + 1] + occ[i + 2]) + occ[i] * (((occ[i + 1] * (occ[i + 1] - 1))/2) + ((occ[i + 2] * (occ[i + 2] - 1))/2)) + (occ[i] * occ[i + 1] * occ[i + 2]);
        }

        cout << ans << '\n';
    }

    return 0;
}