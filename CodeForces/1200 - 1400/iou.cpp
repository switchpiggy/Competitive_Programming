#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b, c, res[107];

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);
        res[a] += c;
        res[b] -= c;
    }

    ll ans = 0;

    for(ll i = 1; i <= n; ++i) if(res[i] > 0) ans += res[i];

    printf("%lld\n", ans);

    return 0;
}