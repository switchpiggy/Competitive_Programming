#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, q, l, r, a[200007];
vector<ll> temps;

int main() {
    scanf("%lld %lld %lld", &n, &k, &q);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &l, &r);
        a[l]++;
        a[r + 1]--;
    }

    for(ll i = 1; i <= 200001; ++i) {
        a[i] += a[i - 1];
    }

    for(ll i = 1; i <= 200001; ++i) {
        if(a[i] >= k) a[i] = 1;
        else a[i] = 0;
        a[i] += a[i - 1];
    }

    for(ll i = 0; i < q; ++i) {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", a[r] - a[l - 1]);
    }

    return 0;
}