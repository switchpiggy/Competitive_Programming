#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        occ.clear();
        cin >> n >> m;
        ll ans = 0;
        for(ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            occ[a]++;
        }

        for(ll i = 0; i < m; ++i) {
            ll a;
            cin >> a;
            if(occ[a]) ans++;
        }

        cout << ans << '\n';
    }
}