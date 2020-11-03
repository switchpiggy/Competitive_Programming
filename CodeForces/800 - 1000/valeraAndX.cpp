#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
char grid[307][307];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) cin >> grid[i][j];
    }

    char c = grid[0][0];
    char d = grid[0][1];
    if(c == d) {
        cout << "NO\n";
        return 0;
    }
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(i == j || i == n - j - 1) {
                if(grid[i][j] != c) {
                    cout << "NO\n";
                    return 0;
                }
            } else {
                if(grid[i][j] != d) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    return 0;
}