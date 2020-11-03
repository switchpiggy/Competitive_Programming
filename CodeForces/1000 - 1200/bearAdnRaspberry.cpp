#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, c, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = c;
    for(ll i = 0; i < n - 1; ++i) {
        if(a[i] - a[i + 1] >= c) ans = max(ans, a[i] - a[i + 1]);
    }

    cout << ans - c << '\n';
    return 0;
}