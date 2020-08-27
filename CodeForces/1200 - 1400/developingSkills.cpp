#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[100007], res;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        res += a[i]/10;
        a[i] %= 10;
    }

    sort(a, a + n, greater<ll>());

    for(ll i = 0; i < n; ++i) {
        if(k >= 10 - a[i]) {
            k -= 10 - a[i];
            res++;
        }
    }
    res += k/10;
    res = min(res, n * 10);

    printf("%lld\n", res);
    return 0;
}