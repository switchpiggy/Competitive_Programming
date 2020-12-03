#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ans = max(ans, a[i]);
        for(ll j = i + 1; j < n; ++j) {
            for(ll k = j + 1; k < n; ++k) {
                ans = max(ans, (ll)(a[i] | a[j] | a[k]));
            }

            ans = max(ans, (ll)(a[i] | a[j]));
        }
    }

    cout << ans << '\n';
}