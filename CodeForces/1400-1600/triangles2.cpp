#include <bits/stdc++.h>

using namespace std;

bool grid[100005][100005];

int n;

int dfs(int x, int y) {

    int r = 0, c = 0;

    for(int i = 1; i <= n; ++i) {

        if(grid[x][i]) r++;

        if(grid[i][y]) c++;

    }

    return 

}

int main() {

    cin >> n;

    for(int i = 0; i < n; ++i) {

        int a, b;

        cin >> a >> b;

        grid[a][b] = 1;

    }

}