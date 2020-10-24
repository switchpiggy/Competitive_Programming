#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, h, top[107], l[107], ans[107][107];
bool grid[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    for(ll i = 1; i <= m; ++i) cin >> top[i];
    for(ll i = 1; i <= n; ++i) cin >> l[i];

    for(ll i = 1; i <= n; ++i) 
        for(ll j = 1; j <= m; ++j) cin >> grid[i][j];


    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) if(grid[i][j]) ans[i][j] = min(top[j], l[i]);
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            cout << ans[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}