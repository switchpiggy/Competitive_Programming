#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

ll getAns(ll x) {
    while(x%2 == 0) {
        x /= 2;
    }

    while(x%3 == 0) {
        x /= 3;
    }

    return x;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        a[i] = getAns(a[i]);
    }

    sort(a, a + n);

    for(ll i = 0; i < n - 1; ++i) {
        if(a[i] != a[i + 1]) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}