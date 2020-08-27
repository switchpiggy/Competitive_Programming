#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b, pref[107];

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld", &a, &b);
        pref[a]++;
        pref[b + 1]--;
    }

    for(ll i = 1; i <= n; ++i) pref[i] += pref[i - 1];

    for(ll i = 1; i <= n; ++i) {
        if(pref[i] != 1) {
            printf("%lld %lld\n", i, pref[i]);
            return 0;
        }
    }

    printf("OK\n");
    return 0;
}