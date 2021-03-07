#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
bool grid[4][4];
ll a[4][4], n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(ll i = 1; i <= 3; ++i) 
        for(ll j = 1; j <= 3; ++j) cin >> a[i][j];
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        for(ll j = 1; j <= 3; ++j) {
            for(ll k = 1; k <= 3; ++k) if(a[j][k] == t) grid[j][k] = 1;
        }
    }

    for(ll i = 1; i <= 3; ++i) {
        if(grid[i][1] && grid[i][2] && grid[i][3]) {
            cout << "Yes\n";
            return 0;
        }

        if(grid[1][i] && grid[2][i] && grid[3][i]) {
            cout << "Yes\n";
            return 0;
        }
    }

    if((grid[1][1] && grid[2][2] && grid[3][3]) || (grid[3][1] && grid[2][2] && grid[1][3])) {
        cout << "Yes\n";
    } else cout << "No\n";
    return 0;
}