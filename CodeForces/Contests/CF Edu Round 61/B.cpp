#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[300007], m, q[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll s = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    cin >> m;
    for(ll i = 0; i < m; ++i) cin >> q[i];

    sort(a, a + n);

    for(ll i = 0; i < m; ++i) {
        ll cur = n - q[i];
        cout << s - a[cur] << '\n';
    }

    return 0;
}