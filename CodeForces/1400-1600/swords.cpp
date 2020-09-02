#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll maxn = 0;
    for(ll i = 0; i < n; ++i) maxn = max(maxn, a[i]);

    sort(a, a + n);
    ll gcf = __gcd(maxn - a[0], maxn - a[1]);

    for(ll i = 2; i < n; ++i) {
        if(a[i] == maxn) continue;
        gcf = __gcd(gcf, maxn - a[i]);
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ans += (maxn - a[i])/gcf;
    }

    cout << ans << ' ' << gcf << endl;
    return 0;
}