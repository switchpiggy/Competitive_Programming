#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[200007];

bool check(ll x) {
    ll cuts = 0;
    for(ll i = 0; i < n; ++i) {
        cuts += (a[i] + x - 1)/x - 1;
    }

    return cuts <= k;    
}

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    sort(a, a + n);

    ll l = 1, r = a[n - 1];
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            r = mid;
        } else l = mid + 1;
    }

    printf("%lld\n", l);
    return 0;
}