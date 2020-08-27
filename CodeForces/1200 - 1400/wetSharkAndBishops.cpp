#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
ll x[2007], y[2007];

ll sum(ll x) {
    return (x*(x-1))/2;
}

int main() {
    scanf("%lld", &n);
    while(n--) {
        scanf("%lld %lld", &a, &b);
        x[a + b]++;
        y[a - b + 1000]++;
    }

    ll ans = 0;

    for(ll i = 0; i < 2007; ++i) {
        ans += ((x[i]*(x[i] - 1)/2) + (y[i]*(y[i] - 1)/2));
    }

    printf("%lld\n", ans);

    return 0;
} 