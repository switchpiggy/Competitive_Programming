#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1007];

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);

    ll ans = INT_MAX;

    for(ll i = 1; i <= n; ++i) {

        ll total = 0;
        for(ll j = 1; j <= n; ++j) {
            ll dist = j - i;
            if(dist < 0) dist = n - abs(j - i);

            total += dist * a[j];
        }

        ans = min(total, ans);
    }

    printf("%lld\n", ans);
}