#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll grid[2007][2007], ans = 1001, x = 1000, y = 1000, currentTime = 0, n;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    scanf("%lld", &n);

    for(ll i = 0; i < 2007; ++i) {
        for(ll j = 0; j < 2007; ++j) {
            grid[i][j] = -1;
        }   
    }

    grid[x][y] = 0;
    for(ll m = 0; m < n; ++m) {
        char c;
        ll d;

        cin >> c >> d;

        ll dx = 0, dy = 0;
        if(c == 'N') dy = -1;
        else if(c == 'S') dy = 1;
        else if(c == 'W') dx = -1;
        else dx = 1;

        for(ll i = 1; i <= d; ++i) {
        	currentTime++;
            x += dx;
            y += dy;
            if(grid[x][y] >= 0 && currentTime - grid[x][y] < ans) {
                ans = currentTime - grid[x][y];
            } 
            grid[x][y] = currentTime;
        }
    }

    if(ans == 1001) {
        printf("-1\n");
        return 0;
    }

    printf("%lld\n", ans);

    return 0;
}