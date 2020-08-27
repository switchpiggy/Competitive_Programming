#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    scanf("%lld", &t);
    while(t--) {
        ll ans = 0;

        scanf("%lld", &n);
        for(ll i = 0; i < 60; ++i) {
            if(n & (1ll << i)) {
                ans += (1ll << (i + 1)) - 1;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}