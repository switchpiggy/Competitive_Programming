#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[100007], t[100007], p[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) cin >> t[i];
    for(ll i = 0; i < n; ++i) {
        if(!t[i]) p[i] = a[i];
    }

    for(ll i = 1; i < n; ++i) p[i] += p[i - 1];

    ll ans = 0, res = 0;
    for(ll i = 0; i < n; ++i) if(t[i]) ans += a[i];
    for(ll i = 0; i < n; ++i) {
        res = max(res, ans + p[min(i + k - 1, n - 1)] - (i ? p[i - 1] : 0));
    }

    cout << res << '\n';
    return 0;
}