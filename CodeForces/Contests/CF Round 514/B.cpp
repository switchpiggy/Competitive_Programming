#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
char grid[1007][1007];
bool f[1007][1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> grid[i][j];
    }

    for(ll i = 0; i < n; ++i) f[i][0] = f[i][m - 1] = 1;
    for(ll i = 0; i < m; ++i) f[0][i] = f[n - 1][i] = 1;

    for(ll i = 1; i < n - 1; ++i) {
        for(ll j = 1; j < m - 1; ++j) {
            if(grid[i][j] == '.') { 
                f[i - 1][j] = f[i + 1][j] = f[i][j - 1] = f[i][j + 1] = f[i + 1][j + 1] = f[i - 1][j + 1] = f[i + 1][j - 1] = f[i - 1][j - 1] = 1;
            } 
        }
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 1; j < m; ++j) {
            if(grid[i][j] != '#') continue;
            bool ok = 0;
            if((!f[i - 1][j] && i) || (!f[i + 1][j] && i < n - 1) || (!f[i][j - 1] && j) || (!f[i][j + 1] && j < m - 1) || (!f[i + 1][j + 1] && j < m - 1 && i < n - 1) || (!f[i - 1][j + 1] && i && j < m - 1) || (!f[i + 1][j - 1] && i < n - 1 && j) || (!f[i - 1][j - 1]) && i && j) ok = 1;
            if(!ok) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}
