#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, maxn = 0;
char grid[107][107];

ll getAns(ll x, ll y) {
    ll r = 0, l = 0, u = 0, d = 0;
    while(x + r + 1 < n && grid[x + r + 1][y] == '.') r++;
    while(x - l - 1 >= 0 && grid[x - l - 1][y] == '.') l--;
    while(y - d - 1 >= 0 && grid[x][y - l - 1] == '.') d--;
    while(y + u + 1 < n && grid[x][y + u + 1] == '.') u++;

    return min(k, max(0, l + r - k)) + min(k, max(0, u + d - k));
}

int main() {
    scanf("%lld %lld", &n, &k);

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) scanf("%c", &grid[i][j]);
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            maxn = max(maxn, getAns(i, j)); 
        }
    }

    printf("%lld\n", maxn);

    return 0;
}