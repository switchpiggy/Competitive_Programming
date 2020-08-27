#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t, n, temp;
    scanf("%lld", &t);

    for(ll count = 1; count <= t; ++count) {
        ll ans = 0;
        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &temp);
            if(temp >= 0) ans += temp;
        }
        printf("%lld\n", ans);
    }
}