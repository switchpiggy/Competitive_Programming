#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, r, c, k;
char a[107][107], res[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> r >> c >> k;
        ll rice = 0;
        for(ll i = 0; i < r; ++i) {
            for(ll j = 0; j < c; ++j) {
                cin >> a[i][j];
                res[i][j] = '.';
                rice += (a[i][j] == 'R');
            }
        }

        char cur = 'a';
        ll cell = 0, row = 0, col = 0, dir = 1;
        for(ll i = 0; i < k - 1; ++i) {
            ll goal = rice/k + (i < rice%k);

            while(row < r && col < c && goal) {
                res[row][col] = cur;
                goal -= (a[row][col] == 'R');
                if(dir == 1) {
                    if(col == c - 1) {
                        dir = -1;
                        row++;
                    } else col++;
                } else {
                    if(col == 0) {
                        dir = 1;
                        row++;
                    } else col--;
                }
            }

            if(cur == 'z') cur = 'A';
            else if(cur == 'Z') cur = '0';
            else cur++;
        }

        for(ll i = 0; i < r; ++i, cout << '\n') {
            for(ll j = 0; j < c; ++j) {
                if(res[i][j] == '.') cout << cur;
                else cout << res[i][j];
            }
        }
        //cout << cur << '\n';
    }

    return 0;
}