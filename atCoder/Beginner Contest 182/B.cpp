#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0, maxn = 0;
    for(ll i = 2; i <= 1000; ++i) {
        ll cur = 0;
        for(ll j = 0; j < n; ++j) cur += (a[j]%i == 0);

        if(cur > maxn) {
            maxn = cur;
            ans = i;
        }
    }

    cout << ans << '\n';
    return 0;
}