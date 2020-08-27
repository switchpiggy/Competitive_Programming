#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int ll;
ll n, m, dx, dy, grid[35][35], ans = INT_MAX;
pair<ll, ll> start;

void bfs(ll r, ll c, ll cnt, bool visited[35][35]) {
    if(r < 0 || r >= n || c < 0 || c >= m || visited[r][c]) return; 
    if(grid[r][c] == 0 || grid[r][c] == 2) return;
    if(grid[r][c] == 4) {
        ans = min(ans, cnt);
        return;
    }
    cnt++;

    visited[r][c] = 1;

    bfs(r + dx, c + dy, cnt, visited);
    bfs(r - dx, c + dy, cnt, visited);
    bfs(r + dx, c - dy, cnt, visited);
    bfs(r - dx, c - dy, cnt, visited);
    bfs(r + dy, c + dx, cnt, visited);
    bfs(r - dy, c + dx, cnt, visited);
    bfs(r + dy, c - dx, cnt, visited);
    bfs(r - dy, c - dx, cnt, visited);

    return;
}

int main() {
    scanf("%lld %lld %lld %lld", &n, &m, &dx, &dy);

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            scanf("%lld ", &grid[i][j]);
            if(grid[i][j] == 3) start = make_pair(i, j);
        }
    }

    bfs(start.first, start.second, 0);

    printf("%lld\n", ans);

    return 0;
}