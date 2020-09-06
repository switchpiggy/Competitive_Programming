#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, w, q, r1, c1, r2, c2, hor[507][507], ver[507][507];
char grid[507][507];

bool ok(ll r, ll c) {
    if(r > h || r <= 0 || c > w || c <= 0 || grid[r][c] == '#') return 0;
    return 1; 
}

int main() {
    cin >> h >> w;
    for(ll i = 1; i <= h; ++i) {
        for(ll j = 1; j <= w; ++j) cin >> grid[i][j];
    }

    for(ll i = 1; i <= h; ++i) {
        for(ll j = 1; j <= w; ++j) {
            if(grid[i][j] == '#') ver[i][j] = hor[i][j] = 0;
            else {
                if(ok(i, j + 1)) hor[i][j]++;
                if(ok(i + 1, j)) ver[i][j]++;
            }
        }
    }

    for(ll i = 1; i <= h; ++i) {
        hor[i][1] += hor[i - 1][1];
        ver[i][1] += ver[i - 1][1];
    }

    for(ll i = 1; i <= w; ++i) {
        hor[1][i] += hor[1][i - 1];
        ver[1][i] += ver[1][i - 1];
    }

    for(ll i = 2; i <= h; ++i) {
        for(ll j = 2; j <= w; ++j) {
            hor[i][j] += hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1];
            ver[i][j] += ver[i - 1][j] + ver[i][j - 1] - ver[i - 1][j - 1];
        }
    }

    /*for(ll i = 1; i <= h; ++i) {
        for(ll j = 1; j <= w; ++j) cout << ver[i][j] << ' ';
        cout << endl;
    }

    cout << endl;
    for(ll i = 1; i <= h; ++i) {
        for(ll j = 1; j <= w; ++j) cout << hor[i][j] << ' ';
        cout << endl;
    }*/

    cin >> q;
    for(ll i = 0; i < q; ++i) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (ver[r1 - 1][c1 - 1] + ver[r2 - 1][c2] - ver[r2 - 1][c1 - 1] - ver[r1 - 1][c2])  + (hor[r1 - 1][c1 - 1] + hor[r2][c2 - 1] - hor[r2][c1 - 1] - hor[r1 - 1][c2 - 1]) << '\n';
    }

    return 0;
}