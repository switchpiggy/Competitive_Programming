#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

char grid[505][505];
ll n, m, a, b, c, d;
char dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool dfs(ll x, ll y) {
    if(grid[x][y] != '.') {
        if(x == c && y == d) return 1;
        return 0;
    }
    grid[x][y] = 'X';
    for(ll i = 0; i < 4; ++i) {
        if(dfs(x + dx[i], y + dy[i])) return 1;
    }
    return 0;
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; ++i) scanf("%s", grid[i] + 1);
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    grid[a][b] = '.';
    if(dfs(a, b)) printf("YES\n");
    else printf("NO\n");
}