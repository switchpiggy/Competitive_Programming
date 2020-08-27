#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, grid[1007][1007], a, b;

bool checkSquare(ll r, ll c) {
    if(!(r < n && r >= 0 && c < n && c >= 0 && r + 2 < n && c + 2 < n)) return 0;
    if(grid[r][c] && grid[r][c + 1] && grid[r][c + 2] && grid[r + 1][c] && grid[r + 1][c + 1] && grid[r + 1][c + 2] && grid[r + 2][c] && grid[r + 2][c + 1] && grid[r + 2][c + 2]) return 1;
    return 0;
}

bool checkAns(ll r, ll c) {
    if(checkSquare(r - 2, c - 2) || checkSquare(r - 2, c - 1) || checkSquare(r - 2, c) || checkSquare(r - 1, c - 2) || checkSquare(r - 1, c - 1) || checkSquare(r - 1, c) || checkSquare(r, c - 2) || checkSquare(r, c - 1) || checkSquare(r, c)) return 1;
    return 0;
}

int main() {
    scanf("%lld %lld", &n, &m);

    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld", &a, &b);
        a--;
        b--;
        grid[a][b] = 1;
        if(i >= 8 && checkAns(a, b)) {
            printf("%lld\n", i + 1);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}