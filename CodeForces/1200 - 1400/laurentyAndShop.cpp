#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[2][57], b[57];

int main() {
    scanf("%lld", &n);
    a[0][1] = a[1][1] = 0;

    for(ll i = 0; i < 2; ++i) {
        for(ll j = 2; j <= n; ++j) {
            scanf("%lld", &a[i][j]);
            a[i][j] += a[i][j - 1];
        }
    }

    for(ll i = 1; i <= n; ++i) scanf("%lld", &b[i]);

    ll mins = INT_MAX, minx = INT_MAX, prev;
    for(ll i = 1; i <= n; ++i) {
        if(a[0][i] + b[i] + (a[1][n] - a[1][i]) < mins) {
            mins = a[0][i] + b[i] + (a[1][n] - a[1][i]);
            prev = i;
        }
    }

    for(ll i = 1; i <= n; ++i) {
        if(i == prev) continue;
        if((a[1][n] - a[1][i]) + a[0][i] + b[i] < minx) {
            minx = a[0][i] + b[i] + (a[1][n] - a[1][i]);
        }
    }

    printf("%lld\n", mins + minx);

    return 0;
}