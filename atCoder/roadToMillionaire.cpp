#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[87];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    ll ans = 1000;
    for(ll i = 0; i < n - 1; ++i) {
        if(a[i] < a[i + 1]) {
            ll cur = ans%a[i];
            ans = (ans/a[i]) * a[i + 1];
            ans += cur;
        }
    }

    printf("%lld\n", ans);
    return 0;
}