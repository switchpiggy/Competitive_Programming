#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	ll n, a, b, c;
    scanf("%lld %lld %lld %lld", &n, &a, &b, &c);

    ll d;

    if(n%4 == 0 && n >= 4) {
        printf("0\n");
        return 0;
    }

    for(ll i = 1; i <= 3; ++i) {
        if((n + i)%4 == 0) {
            d = i;
            break;
        }
    }

    if(d == 1) {
        printf("%lld\n", min(a, min(3 * c, c + b)));
    } else if(d == 2) {
        printf("%lld\n", min(2 *  a, min(b, 2 * c)));
    } else if(d == 3) {
        printf("%lld\n", min(3 * a, min(a + b, c)));
    }

    return 0;
}