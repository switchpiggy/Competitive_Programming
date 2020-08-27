#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll c, n, w[20], ans = 0;

int main() {
    scanf("%lld %lld", &c, &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &w[i]);

    for(ll mask = 0; mask < pow(2, n); ++mask) {
        ll total = 0;
        for(ll i = 0; i < n; ++i) {
            if(mask & (1 << i)) total += w[i];
        }

        if(total <= c) ans = max(ans, total);
    }

    printf("%lld\n", ans);

    return 0;
}