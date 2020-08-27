#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, b, h[27], ans = INT_MAX;

int main() {
    scanf("%lld %lld", &n, &b);
    for(ll i = 0; i < n; ++i) scanf("%lld", &h[i]);

    for(ll mask = 0; mask < pow(2, n); ++mask) {
        ll total = 0;
        for(ll i = 0; i < n; ++i) {
            if(mask & (1 << i)) total += h[i];
        }

        if(total >= b) ans = min(ans, total);
    }

    printf("%lld\n", ans);

    return 0;
}