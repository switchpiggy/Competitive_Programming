#include <bits/stdc++.h>
using namespace std;

//Be careful of corner cases. For example, when all flowers are equally beautiful, the general algorithm we used doesn't work, so we have to compensate for that case.

typedef long long int ll;

ll n, a[200005], minn, maxn, minc, maxc;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    sort(a, a + n);

    minn = a[0], maxn = a[n - 1];

    for(ll i = 0; i < n; ++i) {
        if(a[i] == minn) minc++;
        else break;
    }

    for(ll i = n - 1; i >= 0; --i) {
        if(a[i] == maxn) maxc++;
        else break;
    }

    if(maxn == minn && maxc == minc && minc == n) {
        printf("0 %lld\n", n*(n-1)/2);
        return 0;
    }

    printf("%lld %lld\n", maxn - minn, maxc * minc);
    
}