#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[57];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    ll maxn = 0, cur = 0, t;
    for(ll i = n; i >= 1; --i) {
        t = max(maxn, cur - maxn + a[i]);
        cur += a[i];
        maxn = t;
    }

    cout << cur - maxn << ' ' << maxn << '\n';
}