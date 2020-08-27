#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll m, n;

int main() {
    scanf("%lld %lld", &n, &m);
    ll l = m - 1, r = n - m;

    if(n == 1) {
        printf("1\n");
        return 0;
    } else if(l >= r) {
        printf("%lld", m - 1);
    } else {
        printf("%lld", m + 1);
    }

    return 0;
}