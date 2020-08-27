#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &a, &b);

        ll mins = min(a, b);
        ll maxs = max(a, b);

        if(maxs%mins != 0 || ((maxs/mins) & (maxs/mins - 1)) != 0) {
            printf("-1\n");
            continue;
        }

        ll q = (ll)log2(maxs/mins);
        ll ans = 0;

        if(q%3) ans++;
        ans += q/3;

        printf("%lld\n", ans);
    }

    return 0;
}