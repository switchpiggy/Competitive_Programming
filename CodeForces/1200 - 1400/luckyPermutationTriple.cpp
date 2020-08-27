#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    scanf("%lld", &n);

    if(n%2 == 0) {
        printf("-1\n");
        return 0;
    }

    for(ll i = 0; i < n; ++i) printf("%lld ", i);
    printf("\n");
    
    for(ll i = 0; i < n; ++i) printf("%lld ", i);
    printf("\n");

    for(ll i = 0; i < n; ++i) {
        printf("%lld ", (2 * i)%n);
    }

    return 0;
}