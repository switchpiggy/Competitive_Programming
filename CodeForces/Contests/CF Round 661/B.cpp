#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[57], b[57];

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        ll mina = INT_MAX, minb = INT_MAX;
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            mina = min(mina, a[i]);
        }

        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &b[i]);
            minb = min(minb, b[i]);
        }

        ll ans = 0;
        for(ll i = 0; i < n; ++i) {
            ans += min(a[i] - mina, b[i] - minb);
            ans += abs((a[i] - mina) - (b[i] - minb));
        }

        printf("%lld\n", ans);
    }

    return 0;
}