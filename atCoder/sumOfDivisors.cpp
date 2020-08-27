#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    scanf("%lld", &n);
    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ans += (i * (n/i) * (n/i + 1))/2;
    }

    printf("%lld\n", ans);
    return 0;
}