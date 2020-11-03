#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll grid[4][4], row[4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 1; i <= 3; ++i) {
        for(ll j = 1; j <= 3; ++j) {
            cin >> grid[i][j];
            row[i] += grid[i][j];
        }
    }

    ll maxn = *max_element(row + 1, row + 4);
    maxn++;
    grid[1][1] = maxn - row[1];
    grid[2][2] = maxn - row[2];
    grid[3][3] = maxn - row[3];

    ll diff = grid[1][3] + grid[3][1] - grid[1][1] - grid[3][3];
    grid[1][1] += diff/2;
    grid[2][2] += diff/2;
    grid[3][3] += diff/2;

    for(ll i = 1; i <= 3; ++i) {
        for(ll j = 1; j <= 3; ++j) {
            cout << grid[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}