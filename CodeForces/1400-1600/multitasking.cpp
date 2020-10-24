#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, grid[1000][100], k;

void asc() {
    for(ll i = 1; i < m; ++i) {
        for(ll j = i + 1; j <= m; ++j) cout << i << ' ' << j << '\n';
    }

    exit(0);
}

void desc() {
    for(ll i = 1; i < m; ++i) {
        for(ll j = i + 1; j <= m; ++j) cout << j << ' ' << i << '\n';
    }

    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(ll i = 0; i < n; ++i) 
        for(ll j = 0; j < m; ++j) cin >> grid[i][j];

    cout << (m * (m - 1))/2 << '\n';
    if(!k) asc();
    desc();

    return 0;
}