#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k;

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);

    if(k < n) {
        printf("%lld 1\n", k + 1);
        return 0;
    }

    k -= n;
    ll r = k/(m - 1);

    if(r%2 == 1) {
        printf("%lld %lld\n", n - r, m - k%(m - 1));
    } else {
        printf("%lld %lld\n", n - r, k%(m - 1) + 2);
    }

    return 0;
}