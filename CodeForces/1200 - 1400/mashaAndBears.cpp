#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, m;

int main() {
    scanf("%lld %lld %lld %lld", &a, &b, &c, &m);

    for(ll i = 2 * m + 1; i <= 2 * a; ++i) {
        for(ll j = 2 * m + 1; j <= 2 * b; ++j) {
            if(i > j)
            for(ll k = max(m, c); k <= 2 * c; ++k) {
                if(j > k && k <= 2 * m && i >= a && j >= b && k >= c) {
                    printf("%lld\n%lld\n%lld\n", i, j, k);
                    return 0;
                }
            }
        }
    }
    
    printf("-1\n");
    
    return 0;
}