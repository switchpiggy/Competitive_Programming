#include <iostream>
using namespace std;

typedef long long int ll;
ll r, c, cnt = 0, grid[1007][1007];

void floodfill(ll cr, ll cc) {
    if(cr >= r || cr < 0 || cc < 0 || cc >= c || !grid[cr][cc]) return;
    grid[cr][cc] = 0;

    for(ll i = -1; i <= 1; ++i) {
        for(ll j = -1; j <= 1; ++j) {
            if(i == 0 && j == 0) continue;
            floodfill(cr + i, cc + j);
        }
    }
    
    return;
}

int main() {
    scanf("%lld %lld", &r, &c);
    for(ll i = 0; i < r; ++i) {
        for(ll j = 0; j < c; ++j) scanf("%lld", &grid[i][j]);
    }

    for(ll i = 0; i < r; ++i) {
        for(ll j = 0; j < c; ++j) {
            if(grid[i][j]) {
                cnt++;
                floodfill(i, j);
            }
        }
    }

    printf("%lld\n", cnt);

    return 0;
}