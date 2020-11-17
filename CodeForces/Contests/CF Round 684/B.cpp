#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(ll i = 0; i < n * k; ++i) cin >> a[i];

        sort(a, a + n * k);

        ll ans = 0, cur = 0;
        for(ll i = n * k - (n/2) - 1; i >= 0 && cur < k; i -= n/2 + 1) {
            ans += a[i];
            cur++;
        }

        cout << ans<< '\n';
    }

    return 0;
}