#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, w, dp[1007][1007];
char grid[1007][1007];

int main() {
    cin >> h >> w;
    for(ll i = 1; i <= h; ++i) {
        for(ll j = 1; j <= w; ++j) cin >> grid[i][j];
    }

    dp[1][1] = 0;

    bool ok = 1;
    for(ll i = 1; i <= h; ++i) {
        if(grid[i][1] == '#') ok = 0;

        if(ok) dp[i][1] = 1;
    }

    ok = 1;
    for(ll i = 1; i <= w; ++i) {
        if(grid[1][i] == '#') ok = 0;

        if(ok) dp[1][i] = 1;
    }

    for(ll i = 2; i <= h; ++i) {
        for(ll j = 2; j <= w; ++j) {
            if(grid[i][j] == '#') dp[i][j] = 0;
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= 1000000007;
            }
        }
    }

    /*for(ll i = 1; i <= h; ++i) {
        for(ll j = 1; j <= w; ++j) {
            cout << dp[i][j] << ' ';
        }

        cout << endl;
    }*/

    cout << dp[h][w] << endl;
    return 0;
}