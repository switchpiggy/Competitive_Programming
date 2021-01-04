#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, q, a[200007], cur[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> q;
    for(ll i = 1; i <= q; ++i) cin >> a[i];
    for(ll i = 1; i <= n; ++i) cur[i] = k;

    for(ll i = 1; i <= q; ++i) {
        cur[a[i]]++;
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        if(cur[i] <= q) cout << "No\n";
        else cout << "Yes\n";
    }

    //cout << ans << '\n';
    return 0;
}