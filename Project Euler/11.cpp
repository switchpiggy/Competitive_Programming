#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll grid[25][25], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}; 

int main() {
    for(ll i = 0; i < 20; ++i) {
        for(ll j = 0; j < 20; ++j) cin >> grid[i][j];
    }

    ll res = 0;

    for(ll i = 0; i < 20; ++i) {
        for(ll j = 0; j < 20; ++j) {
            ll ans = 0;
            if(i + 3 < 20) ans = max(ans, grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]);
            if(i - 3 >= 0) ans = max(ans, grid[i][j] * grid[i - 1][j] * grid[i - 2][j] * grid[i - 3][j]);
            if(j + 3 < 20) ans = max(ans, grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3]);
            if(j - 3 >= 0) ans = max(ans, grid[i][j] * grid[i][j - 1] * grid[i][j - 2] * grid[i][j - 3]);
            if(i - 3 >= 0 && j - 3 >= 0) ans = max(ans, grid[i][j] * grid[i - 1][j - 1] * grid[i - 2][j - 2] * grid[i - 3][j - 3]);
            if(i - 3 >= 0 && j + 3 < 20) ans = max(ans, grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3]);
            if(i + 3 < 20 && j + 3 < 20) ans = max(ans, grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3]);
            if(i + 3 < 20 && j - 3 >= 0) ans = max(ans, grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3]);
            res = max(ans, res);
        }
    }

    cout << res << endl;
    return 0;
}