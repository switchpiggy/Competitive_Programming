#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], ans[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);

    ll cur = 0;
    for(ll i = 1; i < n; i += 2) {
        ans[i] = a[cur];
        cur++;
    }

    for(ll i = 0; i < n; i += 2) {
        ans[i] = a[cur];
        cur++;
    }

    cout << n/2 - (n%2 == 0) << '\n';

    for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}