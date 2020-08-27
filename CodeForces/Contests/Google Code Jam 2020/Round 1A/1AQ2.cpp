#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool visited[501][501];
int pascal[501][501];
ll t, n;
vector<pair<int, int>> path;
int dir[6][2] = {
    {-1, -1},
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0},
    {1, 1},
};

void populateTriangle() {
    pascal[1][1] = 1;
    for(int i = 2; i <= 500; ++i) {
        for(int j = 1; j <= i; ++j) {
            if(j == i || j == 1) pascal[i][j] = 1;
            else pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
}

bool check(int row, int col) {
    if(row < 1 || col < 1) return false;
    if(col > row) return false;
    return true;
}

bool dfs(int sum, int row, int col) {
    if(visited[row][col]) return false;
    if(sum == n) {
        for(int i = 0; i < path.size(); ++i) printf("%d %d\n", path[i].first, path[i].second);
        return true;
    }
    if(sum > n) {
        path.pop_back();
        return false;
    }
    visited[row][col] = 1;
    path.push_back(make_pair(row, col));
    for(int i = 0; i < 6; ++i) {
        int nextI = row + dir[i][0];
        int nextJ = col + dir[i][1];
       if(check(nextI, nextJ)) if(dfs(sum + pascal[nextI][nextJ], nextI, nextJ)) return true;
    }
    visited[row][col] = 0;
    path.pop_back();
    return false;
    
}

int main() {
    populateTriangle();
    scanf("%lld", &t);
    for(ll tc = 1; tc <= t; ++tc) {
        memset(visited, 0, sizeof(visited[0][0]) * 501 * 501);
        path.clear();
        scanf("%lld", &n);
        dfs(0, 1, 1);
    }
}