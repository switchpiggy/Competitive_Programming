#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

ll largestFactor(ll x) {
    ll ans = -1;
    for(ll i = 2; i <= sqrt(x); ++i) {
        if(x%i == 0) ans = max(ans, max(i, x/i));
    }

    return ans;
}

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        ll f = largestFactor(n);
        if(f == -1) {
            if(n != 1) n--;
            printf("1 %lld\n", n);
        } else {
            printf("%lld %lld\n", f, n - f);
        }
    }

    return 0;
}