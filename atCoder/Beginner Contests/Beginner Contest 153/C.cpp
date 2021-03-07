#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, h[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> h[i];
    sort(h, h + n);
    ll ans = 0;
    for(ll i = 0; i < max(0ll, n - k); ++i) ans += h[i];

    cout << ans << '\n';
    return 0;
}