#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[107];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    ll res = 0;

    for(ll i = 0; i < n - 1; ++i) {
        if((a[i] == 2 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 2)) {
            printf("Infinite\n");
            return 0;
        }

        if((a[i] == 2 && a[i + 1] == 1) || (a[i] == 1 && a[i + 1] == 2)) {
            res += 3;
        }
        else if((a[i] == 1 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 1)) {
            res += 4;
            if(a[i] == 3 && a[i + 1] == 1 && i + 2 < n && a[i + 2] == 2) res--;
        }
    }

    printf("Finite\n%lld\n", res);
}