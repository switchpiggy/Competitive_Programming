#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[50007];

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }

        bool ok = 0;

        for(ll i = 2; i < n; ++i) {
            if(a[i] >= a[0] + a[1]) {
                printf("1 2 %lld\n", i + 1);
                ok = 1;
                break;
            }
        }

        if(!ok) printf("-1\n");
    }

    return 0;
}