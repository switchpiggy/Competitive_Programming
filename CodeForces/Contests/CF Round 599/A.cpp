#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[1007], occ[1007];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        memset(occ, 0, sizeof(occ));
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            occ[a[i]]++;
        }

        //sort(a, a + n);

        ll ans = 0;

        ll cur = 0;
        for(ll i = n; i >= 1; --i) {
            cur += occ[i];
            if(cur >= i) {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}