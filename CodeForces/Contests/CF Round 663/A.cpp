#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        for(ll i = 1; i <= n; ++i) printf("%lld ", i);
        printf("\n");
    }

    return 0;
}