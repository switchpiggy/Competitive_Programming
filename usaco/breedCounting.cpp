#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, pref[3][100007], a, b;

int main() {
    scanf("%lld %lld", &n, &q);
    for(ll i = 1; i <= n; ++i) {
        scanf("%lld", &a);
        pref[--a][i]++;
    }

    pref[0][0] = pref[1][0] = pref[2][0] = 0;

    for(ll i = 1; i <= n; ++i) {
        pref[0][i] += pref[0][i - 1];
        pref[1][i] += pref[1][i - 1];
        pref[2][i] += pref[2][i - 1];
    }

    for(ll i = 1; i <= q; ++i) {
        scanf("%lld %lld", &a, &b);
        printf("%lld %lld %lld\n", pref[0][b] - pref[0][a - 1], pref[1][b] - pref[1][a - 1], pref[2][b] - pref[2][a - 1]);
    }

    return 0;
}