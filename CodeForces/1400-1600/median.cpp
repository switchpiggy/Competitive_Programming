#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    ll ans = 0;
    while(a[(n + 1)/2 - 1] != x) {
        n++;
        a[n - 1] = x;
        ans++;
        sort(a, a + n);
    }

    cout << ans << '\n';
    return 0;
}