#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll n, a[300005];

    scanf("%lld", &n);
    for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);

    sort(a, a + n);

    if(n%2 == 0) printf("%lld", a[n/2 - 1]);
    else printf("%lld", a[n/2]);
}