#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
char grid[507][507];

int main() {
    cin >> n >> m;
    ll maxx = 0, minx = INT_MAX, miny = INT_MAX, maxy = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == 'X') {
                maxx = max(maxx, i);
                minx = min(minx, i);
                miny = min(miny, j);
                maxy = max(maxy, j);
            }
        } 
    }

    for(ll i = minx; i <= maxx; ++i) {
        for(ll j = miny; j <= maxy; ++j) {
            if(grid[i][j] == '.') {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}