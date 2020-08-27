#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[105], t, ans = -1;


int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    scanf("%lld", &t);

    sort(a, a + n);

    for(ll i = 0; i < n; ++i) {
        ll j = i;
        while(a[i] + t >= a[j] && j < n) j++;

        ans = max(ans, j - i);
    }

    printf("%lld", ans);
}