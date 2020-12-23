#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[50007], nxt[50007], mx[50007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);
    for(ll i = 0; i < n; ++i) {
        ll j = upper_bound(a, a + n, a[i] + k) - a;
        j--;
        nxt[i] = j;
    }

    for(ll i = n - 1; i >= 0; --i) {
        mx[i] = max(nxt[i] - i + 1, mx[i + 1]);
    }

    ll ans = 0;
    for(ll i = 0; i < n - 1; ++i) {
        ans = max(ans, (nxt[i] - i + 1) + mx[nxt[i] + 1]);
    }

    //for(ll i = 0; i < n; ++i) cout << mx[i] << ' ';

    cout << ans << '\n';
    return 0;
}