#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, ans;

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j <= m; ++j) {
            ll w = min(i, n - i), h = min(j, m - j);
            ans += w * h;
        }
    }

    printf("%lld\n", ans);

    return 0;
}