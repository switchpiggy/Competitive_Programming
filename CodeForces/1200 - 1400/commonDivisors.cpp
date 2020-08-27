#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, a[400007];

ll getNumFactors(ll x) {

    ll cur = 0;

    for(ll i = 1; i <= sqrt(x); ++i) {
        if(x%i == 0) {
            cur++;
            if(i != x/i) {
                cur++;
            }
        }
    }

    return cur;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    sort(a, a + n);

    ll cur = a[0];

    for(ll i = 1; i < n; ++i) {
        cur = __gcd(cur, a[i]);
    }

    printf("%lld", getNumFactors(cur));

}