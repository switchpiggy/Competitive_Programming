#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll grid[4][4] = {
{8, 9, 1, 13},
{3, 12, 7, 5},
{0, 2, 4, 11},
{6, 10, 15, 14}
};

ll n, res[1007][1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll cur = 0;
    for(ll i = 0; i < n/4; ++i) {
        for(ll j = 0; j < n/4; ++j) {
            for(ll k = 0; k < 4; ++k) {
                for(ll l = 0; l < 4; ++l) {
                    res[i * 4 + k][j * 4 + l] = grid[k][l] + cur;
                }
            }

            cur += 16;
        }
    }

    for(ll i = 0; i < n; ++i, cout << '\n') {
        for(ll j = 0; j < n; ++j) cout << res[i][j] << ' ';
    }

    return 0;
}