#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
char grid[57][57];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) cin >> grid[i][j];
    }

    for(ll i = 1; i < n - 1; ++i) {
        for(ll j = 1; j < n - 1; ++j) {
            if(grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j - 1] && grid[i][j] == '.') {
                grid[i][j] = grid[i + 1][j] = grid[i - 1][j] = grid[i][j + 1] = grid[i][j - 1] = '#';
            }
        }
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(grid[i][j] == '.') {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}