#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, grid[107][107], res = INT_MAX;

void partition(ll up, ll down) {
    res = min(res, down - up + 1);
    if(down - up + 1 == 1 || (down - up + 1)%2 == 1) return;

    ll mid = (up + down)/2;
    for(ll i = up; i <= mid; ++i) {
        for(ll j = 1; j <= m; ++j) {
            if(grid[i][j] != grid[down - (i - up)][j]) return;
        }
    }

    partition(up, mid);
    partition(mid + 1, down);
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) scanf("%lld", &grid[i][j]);
    }

    partition(1, n);

    printf("%lld\n", res);

    return 0;
}