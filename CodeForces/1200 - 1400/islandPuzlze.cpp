#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, a[200007], b[200007];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i - x]);
        if(!a[i - x]) x = 1;
    }

    x = 0;

    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &b[i - x]);
        if(!b[i - x]) x = 1;
        if(b[i - x] == a[0]) {
            y = i - x;
        }
    }

    n--;
    rotate(b, b + y, b + n);

    for(ll i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}