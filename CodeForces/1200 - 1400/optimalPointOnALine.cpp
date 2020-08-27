#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[300007];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    sort(a, a + n);
    printf("%lld\n", a[n/2 - 1]);
    return 0;
}