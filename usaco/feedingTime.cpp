#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll w, h, cnt = 0, ans = 0;
char grid[757][757];

void floodfill(ll i, ll j) {
    if(i >= h || j >= w || i < 0 || j < 0 || grid[i][j] == '*') return;
    grid[i][j] = '*';
    cnt++;

    for(ll a = -1; a <= 1; ++a) {
        for(ll b = -1; b <= 1; ++b) {
            floodfill(i + a, j + b);
        }
    }

    return;
}

int main() {
    scanf("%lld %lld", &w, &h);
    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) cin >> grid[i][j];
    }

    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) {
            if(grid[i][j] === '.') {
                cnt = 0;
                floodfill(i, j);
                ans = max(ans, cnt);
            }
        }
    }
}