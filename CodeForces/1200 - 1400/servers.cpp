#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, t, k, d, nxt[107];

int main() {
    scanf("%lld %lld", &n, &q);
    for(ll i = 0; i < q; ++i) {
        scanf("%lld %lld %lld", &t, &k, &d);
        ll cnt = 0;
        for(ll i = 1; i <= n && cnt < k; ++i) {
            if(nxt[i] < t) cnt++;
        }

        if(cnt == k) {
            ll cur = 0, sum = 0;
            for(ll i = 1; i <= n && cur < k; ++i) {
                if(nxt[i] < t) {
                    nxt[i] = t + d - 1;
                    sum += i;
                    cur++;
                }
            }

            printf("%lld\n", sum);
        } else printf("-1\n");
    }

    return 0;
}