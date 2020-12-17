#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, d[57];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> d[i];
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) ans += (d[i] * d[j]);
    }

    cout << ans << '\n';
    return 0;
}