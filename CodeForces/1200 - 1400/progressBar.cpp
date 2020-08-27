#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t, k, res[107];

int main() {
    scanf("%lld %lld %lld", &n, &k, &t);
    ll total = (ll)floor((n * t * k)/100);

	ll i = 0;
    for(i = 0; i < floor(total/k); ++i) res[i] = k;
    res[i] = total - floor(total/k) * k;

    for(ll i = 0; i < n; ++i) printf("%lld ", res[i]);

    return 0;
}