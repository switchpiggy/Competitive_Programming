#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[2007];
map<ll, ll> occ;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = n - 1;
    for(ll i = 0; i < n; ++i) {
        occ.clear();
        bool ok = 1;
        for(ll j = 0; j < i; ++j) {
            occ[a[j]]++;
            if(occ[a[j]] >= 2) {
                ok = 0;
                break;
            }
        }

        ll minx = n;
        for(ll j = n - 1; j >= i; --j) {
            occ[a[j]]++;
            if(occ[a[j]] >= 2) {
                break;
            }

            minx = j;
        }

        if(ok) {
            //cout << minx << ' ' << i << endl;
            ans = min(ans, minx - i);
        }
    }

    cout << ans << endl;

    return 0;
}