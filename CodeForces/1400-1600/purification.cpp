#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
char grid[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    bool row = 0, col = 0;
    for(ll i = 0; i < n; ++i) {
        bool ok = 0;
        for(ll j = 0; j < n; ++j) {
            if(grid[i][j] != 'E') {
                ok = 1;
                break;
            }
        }

        if(!ok) {
            row = 1;
            break;
        }
    }

    for(ll j = 0; j < n; ++j) {
        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            if(grid[i][j] != 'E') {
                ok = 1;
                break;
            }
        }

        if(!ok) {
            col = 1;
            break;
        }
    }

    //im not ok
    if(row && col) {
        cout << "-1\n";
        return 0;
    }

    if(!row) {
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                if(grid[i][j] == '.') {
                    cout << i + 1 << ' ' << j + 1 << '\n';
                    break;
                }
            }
        }
    } else {
        for(ll j = 0; j < n; ++j) {
            for(ll i = 0; i < n; ++i) {
                if(grid[i][j] == '.') {
                    cout << i + 1 << ' ' << j + 1 << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}