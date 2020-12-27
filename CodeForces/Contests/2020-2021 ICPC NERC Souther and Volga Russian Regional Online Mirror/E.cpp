#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a[4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        for(ll i = 0; i < 4; ++i) cin >> a[i];
        
        ll ans = 0;
        for(ll i = 0; i < 4; ++i) {
            for(ll j = 0; j < 4; ++j) {
                if(i == j) continue;
                ll k = -1, l = -1;
                for(ll jj = 0; jj < 4; ++jj) {
                    if(jj != i && jj != j) {
                        if(k != -1) l = jj;
                        else k = jj;
                    }
                }

                ans = max(ans, min(a[i], a[j]) * min(a[k], a[l]));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}