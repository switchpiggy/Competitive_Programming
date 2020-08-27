#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
char grid[107][107];

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> grid[i][j];
    }

    ll cnt = 0, maxX = -1, minX = INT_MAX, minY = INT_MAX, maxY = -1;

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(grid[i][j] == 'B') {
                cnt++;
                maxX = max(i, maxX);
                minX = min(i, minX);
                minY = min(j, minY);
                maxY = max(j, maxY);
            }
        }
    }

    if(cnt == 0) {
        printf("1\n");
        return 0;
    }
    ll ans = max(maxX - minX + 1, maxY - minY + 1);

    if(ans > n || ans > m) {
        printf("-1\n");
        return 0;
    }

    printf("%lld\n", ans * ans - cnt);

    return 0;
}