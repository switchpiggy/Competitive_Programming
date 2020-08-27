#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[200007];

int main() {
    scanf("%lld %lld", &n, &k);

    ll cnt = 0;

    for(ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] -= min(a[i], k * (a[i - 1]%k != 0) - a[i - 1]%k);
        cnt += (a[i] + k - 1)/k;
    }

    printf("%lld\n", cnt);

    return 0;
}