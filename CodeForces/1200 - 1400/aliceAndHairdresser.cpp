#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, l, a[100007], t, p, d, ans = 0;

int main() {
    scanf("%lld %lld %lld", &n, &m, &l);
    for(ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if(a[i] > l && a[i - 1] <= l) ans += 1;
    }

    for(ll q = 0; q < m; ++q) {
        scanf("%lld", &t);
        if(t == 0) {
            printf("%lld\n", ans);
        } else {
            scanf("%lld %lld", &p, &d);
            if(a[p] <= l && a[p] + d > l) ans += 1 - (a[p - 1] > l) - (a[p + 1] > l);
            a[p] += d; 
        }
    }

    return 0;
}