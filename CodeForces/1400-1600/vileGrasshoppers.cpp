#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll p, y;

int main() {
    scanf("%lld %lld", &p, &y);
    for(ll i = y; i >= 2; --i) {
        if(i <= p) {
            printf("-1\n");
            return 0;
        }

        bool ok = 0;
        for(ll j = 2; j <= sqrt(i) && j <= p; ++j) {
            if(i%j == 0) {
                ok = 1;
                break;
            }
        }

        if(!ok) {
            printf("%lld\n", i);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}