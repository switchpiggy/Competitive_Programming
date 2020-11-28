#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    ll cur = a[(n + 1)/2 - 1], ans = 0;
    for(ll i = 0; i < n; ++i) ans += abs(cur - a[i]);

    cout << ans << '\n';
    return 0;
}