#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a, b, q;

int main() {
    scanf("%lld", &q);
    while(q--) {
        scanf("%lld %lld %lld %lld", &k, &n, &a, &b);
        if(k - (n * a) > 0) {
            printf("%lld\n", n);
            continue;
        }
        ll d = a - b;
        ll n2 = (-1 * (k - n * a) + d)/d; 
        if(n2 > n) {
            printf("-1\n");
            continue;
        }
        
        printf("%lld\n", n - n2);
    }

    return 0;
}