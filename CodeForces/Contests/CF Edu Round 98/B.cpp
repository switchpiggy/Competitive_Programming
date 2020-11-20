#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        //memset(suf, 0, sizeof(suf));
        //memset(pref, 0, sizeof(pref));
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        ll sum = 0;
        for(ll i = 0; i < n; ++i) sum += a[i];

        ll ans = 0, maxn = 0;
        for(ll i = 0; i < n; ++i) {
            maxn = max(maxn, a[i]);
        }

        if((n - 1) * maxn > sum) cout << (n - 1) * maxn - sum << '\n';
        else cout << (n - 1 - (sum%(n - 1)) + n - 1)%(n - 1) << '\n';
    }

    return 0;
}