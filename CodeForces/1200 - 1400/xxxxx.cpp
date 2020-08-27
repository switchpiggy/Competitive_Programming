#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, t, a[100007];

int main() {
    scanf("%lld", &t);

    while(t--) {
        ll sum = 0, l = -1, r = -1;
        scanf("%lld %lld", &n, &x);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            sum += a[i];
            if(a[i]%x) {
                if(l == -1) l = i;
                r = i;
            }
        }

        if(sum%x != 0) {
            printf("%lld\n", n);
            continue;
        }

        if(l == -1 || r == -1) {
            printf("-1\n");
            continue;
        }

        printf("%lld\n", n - min(l + 1, n - r));
    }
}