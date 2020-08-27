#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll m, b;

ll as(ll x) {
    return x*(x+1)/2;
}

int main() {
    scanf("%lld %lld", &m, &b);
    ll maxn = 0;

    for(ll y = b; y >= 0; --y) {
        ll x = m * (b - y);
        maxn = max(maxn, as(x) * (y + 1) + as(y) * (x + 1));
    }

    printf("%lld\n", maxn);

    return 0;
}