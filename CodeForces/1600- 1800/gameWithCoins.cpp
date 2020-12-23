#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    if(n%2 == 0 || n <= 2) {
        cout << "-1\n";
        return 0;
    }

    ll ans = 0;
    for(ll i = n; i >= 2; --i) {
        if(a[i] <= 0) continue;
        ll cur = i/2, maxn = max(a[2 * cur], a[2 * cur + 1]);
        ans += maxn;
        a[2 * cur + 1] -= maxn, a[cur] -= maxn, a[cur * 2] -= maxn;
    }

    cout << ans + max(0ll, a[1]) << '\n';
    return 0;
}