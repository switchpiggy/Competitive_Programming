#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[2007], occ[4007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = a[i] + 1; j <= 4000; ++j) ans += occ[j];

        for(ll j = 0; j < i; ++j) occ[a[i] + a[j]]++;
    }

    cout << ans << '\n';
}