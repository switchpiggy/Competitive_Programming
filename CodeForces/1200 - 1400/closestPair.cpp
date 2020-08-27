#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

int main() {
    scanf("%lld %lld", &n, &k);
    if((n * (n - 1))/2 <= k) {
        printf("no solution\n");
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        printf("0 %lld\n", i);
    }

    return 0;
}