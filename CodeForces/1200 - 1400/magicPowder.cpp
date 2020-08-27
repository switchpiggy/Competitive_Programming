#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[1007], b[1007];

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for(ll i = 0; i < n; ++i) scanf("%lld", &b[i]);
    ll res = 0;
    while(1) {
        ll val = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i] <= b[i]) {
                b[i] -= a[i];
            } else {
                val += a[i] - b[i];
                b[i] = 0;
            }
        }

        if(val <= k) {
            k -= val;
            res++;
        } else break;
    }

    printf("%lld\n", res);

    return 0;
}