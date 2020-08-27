#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    scanf("%lld", &n);

    for(ll a = 0; a <= n/1234567; ++a) {
        for(ll b = 0; b <= n/123456; ++b) {
            ll c = n - (a * 1234567 + b * 123456);
            if(c >= 0 && c%1234 == 0) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}