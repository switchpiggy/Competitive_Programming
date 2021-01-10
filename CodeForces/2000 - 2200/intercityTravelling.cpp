#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1000007], pow2[1000007];

const ll MOD = (119 << 23) + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    pow2[0] = 1;
    for(ll i = 1; i <= n; ++i) pow2[i] = (pow2[i - 1] * 2)%MOD;

    ll res = (pow2[n - 1] * a[0])%MOD, ans = 0;
    for(ll i = 0; i < n; ++i) {
        ans = (ans + res + MOD)%MOD;
        res = (res - (pow2[n - 2 - i] * a[i])%MOD + MOD)%MOD;
        res = (res + (pow2[n - 2 - i] * a[i + 1])%MOD)%MOD;
    }

    cout << ans << '\n';
    return 0;
}