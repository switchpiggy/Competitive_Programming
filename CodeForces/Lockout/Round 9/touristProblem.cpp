#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], p[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    
    sort(a, a + n);
    p[0] = a[0];
    for(ll i = 1; i < n; ++i) p[i] = p[i - 1] + a[i];

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ans += a[i] * i - (i ? p[i - 1] : 0);
        //cout << ans << '\n';
    }

    ans = sum + ans * 2;
    cout << ans/__gcd(ans, n) << ' ' << n/__gcd(ans, n) << '\n';
    return 0;
}