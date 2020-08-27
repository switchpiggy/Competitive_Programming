#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;

ll largestFactor(ll m, ll j) {
    ll ans = m;

    for(ll i = 1; i * i <= m; ++i) {
        if(m%i == 0) {
            if(i <= j) ans = min(ans, m/i);
            if(m/i <= j) ans = min(ans, i);
        }
    }

    return ans;
}

int main() {
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld %lld", &n, &k);

		printf("%lld\n", largestFactor(n, k));
    }

    return 0;
}