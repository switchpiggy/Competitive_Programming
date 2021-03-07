#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, q;
vector<ll> a[17], b[17];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> q;
        while(q--) {
            cin >> x >> y;
            if(y) a[i].push_back(x - 1);
            else b[i].push_back(x - 1);
        }
    }

    ll ans = 0;
    for(ll i = 0; i < (1 << n); ++i) {
        bool ok = 1;
        for(ll j = 0; j < n; ++j) {
            if(i & (1 << j)) {
                for(ll k = 0; k < (ll)a[j].size(); ++k) {
                    if(!(i & (1 << a[j][k]))) {
                        ok = 0;
                        break;
                    }
                }

                for(ll k = 0; k < (ll)b[j].size(); ++k) {
                    if(i & (1 << b[j][k])) {
                        ok = 0;
                        break;
                    }
                }

                //if(ok) ans = max(ans, (ll)__builtin_popcount(i));
                if(!ok) break;
            }

            //if(ok) ans = max(ans, (ll)__builtin_popcount(i));
        }

        if(ok) ans = max(ans, (ll)__builtin_popcount(i));
    }

    cout << ans << '\n';
    return 0;
}