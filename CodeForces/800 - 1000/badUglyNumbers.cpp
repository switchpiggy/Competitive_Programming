#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t;
    scanf("%lld", &t);
    while(t--) {
        ll n;
        scanf("%lld", &n);
        if(n == 1) {
            printf("-1\n");
            continue;
        }
        printf("2");
        for(ll i = 1; i <= n - 1; ++i) {
            printf("3");
        }
        printf("\n");
    }
    return 0;
}