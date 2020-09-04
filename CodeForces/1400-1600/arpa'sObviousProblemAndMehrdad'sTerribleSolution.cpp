#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<ll, ll> occ;
ll n, x, a[100007];

int main() {
    cin >> n >> x;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(occ[x^a[i]]) ans += occ[x^a[i]];
        occ[a[i]]++;
    }

    cout << ans << endl;
    return 0;
}