#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, p[100007];

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i = 1; i <= m; ++i) scanf("%lld", &p[i]);

    ll cur = 1, res = 0, shift = 0;

    while(cur <= m) {
        ll lastval = ((p[cur] - shift - 1)/k + 1) * k + shift;

        while(cur <= m && p[cur] <= lastval) {
            cur++;
            shift++;
        }
        
        res++;
    }

    printf("%lld\n", res);
    return 0;
}