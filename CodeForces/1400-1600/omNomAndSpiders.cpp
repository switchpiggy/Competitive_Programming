#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k;
char grid[2007][2007];

char getGrid(ll r, ll c) {
    if(r >= n || r < 0 || c >= m || c < 0) return '-';
    return grid[r][c];
}

int main() {
    cin >> n >> m >> k;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> grid[i][j];
    }

    for(ll i = 0; i < m; ++i) {
        ll cnt = 0, t = 0;
        for(ll j = 0; j < n; ++j) {
            if(getGrid(j + t, i) == 'U') cnt++;
            if(getGrid(j - t, i) == 'D') cnt++;
            if(getGrid(j, i + t) == 'L') cnt++;
            if(getGrid(j, i - t) == 'R') cnt++;
            t++;
        }

        cout << cnt << ' ';
    }

    return 0;
}