#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[3007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll sum = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        ll ans = 0;
        for(ll i = 1; i <= n; ++i) {
            if(sum%i != 0) continue;
            ll cur = 0, cSum = 0;
            for(ll j = 0; j < n; ++j) {
                cSum += a[j];
                if(cSum == sum/i) {
                    cur++;
                    cSum = 0;
                }
            }

            if(cur == i && cSum == 0) ans = cur;
        }

        cout << n - ans << '\n';
    }

    return 0;
}