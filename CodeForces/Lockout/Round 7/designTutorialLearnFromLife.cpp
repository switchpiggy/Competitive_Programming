#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, f[2007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> f[i];
    sort(f, f + n, greater<ll>());
    ll ans = 0;
    for(ll i = 0; i < n; i += k) {
        ans += (f[i] - 1) * 2;
    }

    cout << ans << '\n';
    return 0;
}