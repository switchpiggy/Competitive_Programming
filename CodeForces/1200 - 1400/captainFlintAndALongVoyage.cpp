#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld", &n);
        ll m = (n + 3)/4;
        for(ll i = 0; i < n - m; ++i) printf("9");
        for(ll i = 0; i < m; ++i) printf("8");
        printf("\n");
    }

    return 0;
}