#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[1007];

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    sort(a, a + n);

    ll cnt = 0;
    for(ll i = 0; i < k; ++i) cnt += a[i];

    printf("%lld\n", cnt);
    return 0;
}