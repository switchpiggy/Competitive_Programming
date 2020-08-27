#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll n, d, e;
    scanf("%lld %lld %lld", &n, &d, &e);

    ll ans = n;
    
    for(ll i = 0; i * e * 5 <= n; ++i) {
        ans = min(ans, (n - (i * 5 * e)) % d);
    }

    printf("%lld", ans);
}