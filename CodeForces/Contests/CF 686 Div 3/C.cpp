#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[200007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        occ.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            if(i && a[i] == a[i - 1]) continue;
            occ[a[i]]++;
        }

        ll ans = INT_MAX;
        for(auto i = occ.begin(); i != occ.end(); ++i) {
            ll cur = i->second + 1 - (a[0] == i->first) - (a[n - 1] == i->first);
            ans = min(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}