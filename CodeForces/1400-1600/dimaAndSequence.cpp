#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];
map<ll, ll> occ;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) {
        ll res = 0;
        for(ll j = 0; j < (ll)log2(a[i]) + 1; ++j) {
            if(a[i] & (1 << j)) res++;
        }
        occ[res]++;
    }

    ll ans = 0;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        ans += ((i->second) * (i->second - 1))/2;
    }

    cout << ans << endl;
    return 0;
}