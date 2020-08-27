#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];
map<ll, ll> occ;

int main() {
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        if(occ[i - a[i]] > 0) ans += occ[i - a[i]];
        occ[i + a[i]]++;
    }

    cout << ans << endl;
    return 0;
}