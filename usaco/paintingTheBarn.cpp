#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a, b, c, d;
ll grid[1007][1007];

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        for(ll j = a; j < c; ++j) {
            grid[j][b]++;
            grid[j][d]--;
        }
    }

    for(ll i = 0; i <= 1000; ++i) {
        for(ll j = 1; j <= 1000; ++j) grid[i][j] += grid[i][j - 1];
    }

    ll ans = 0;

    for(ll i = 0; i <= 1000; ++i) {
        for(ll j = 0; j <= 1000; ++j) if(grid[i][j] == k) ans++;
    }

    printf("%lld\n", ans);

    return 0;
}