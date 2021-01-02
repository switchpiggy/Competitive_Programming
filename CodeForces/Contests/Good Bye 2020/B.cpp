#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x[100007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        occ.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            cin >> x[i];
            occ[x[i]]++;
        }

        sort(x, x + n, greater<ll>());

        for(ll i = 0; i < n; ++i) {
            if(!occ[x[i] + 1] || occ[x[i]] > 1) {
                occ[x[i]]--;
                occ[x[i] + 1]++;
                x[i]++;
            }
        }

        ll ans = 0;
        for(auto i = occ.begin(); i != occ.end(); ++i) if(i->second) ans++;
        cout << ans << '\n';
    }

    return 0;
}