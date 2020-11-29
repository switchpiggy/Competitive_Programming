#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k, c[100007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll ans = INT_MAX;
        occ.clear();
        for(ll i = 0; i < n; ++i) {
            cin >> c[i];
            occ[c[i]]++;
        }

        for(auto i = occ.begin(); i != occ.end(); ++i) {
            ll res = 0;
            for(ll j = 0; j < n; ++j) {
                if(c[j] != i->first) {
                    res++;
                    j += k - 1;
                }
            }

            ans = min(res, ans);
        }

        cout << ans << '\n';
    }

    return 0;
}