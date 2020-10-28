#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
char grid[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) cin >> grid[i][j];
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(((grid[i][j - 1] == 'o') + (grid[i][j + 1] == 'o') + (grid[i + 1][j] == 'o') + (grid[i - 1][j] == 'o'))%2) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}