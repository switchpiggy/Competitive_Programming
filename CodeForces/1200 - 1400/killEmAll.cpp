#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
ll q, n, r, a[100007];
 
int main() {
    scanf("%lld", &q);
    while(q--) {
        scanf("%lld %lld", &n, &r);
        for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
 
        sort(a, a + n);
        n = unique(a, a + n) - a;
 
        ll ans = 0;
        for(ll i = n - 1; i >= 0; --i) {
            ans += (a[i] - r * ans > 0);
        }
 
        printf("%lld\n", ans);
    }
 
    return 0;
}