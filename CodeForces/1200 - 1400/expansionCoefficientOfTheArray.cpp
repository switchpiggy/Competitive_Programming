#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[300007];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    ll cur = INT_MAX;

    for(ll i = 0; i < n; ++i) {
    	//cout << cur << endl;
    	ll as = a[i]/(ll)max(i, n - i - 1);
        cur = (ll)min(cur, as);
    }

    printf("%lld\n", cur);

    return 0;
}