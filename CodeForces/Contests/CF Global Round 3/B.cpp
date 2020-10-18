#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, ta, tb, k, a[200007], b[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> ta >> tb >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < m; ++i) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    if(k >= n) {
        cout << "-1\n";
        return 0;
    }

    ll ans = 0;
    for(ll i = 0; i <= k; ++i) {
        ll cur = lower_bound(b, b + m, a[i] + ta) - b;
        if(cur + (k - i) >= m) {
            cout << "-1\n";
            return 0;
        }

        ans = max(ans, b[cur + (k - i)] + tb);
    }

    cout << ans << '\n';
    return 0;
}