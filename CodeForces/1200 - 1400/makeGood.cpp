#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007];

int main() {
    scanf("%lld", &t);
    while(t--) {
        ll sum = 0, x = 0;
        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            x ^= a[i];
            sum += a[i];
        }

        printf("2\n%lld %lld\n", x, sum + x);
    }

    return 0;
}