#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, w, dist[27][27][27][27];
char grid[27][27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) cin >> grid[i][j];
    }
    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) {
            //cin >> grid[i][j];
            if(grid[i][j] == '#') continue;
            if(i && grid[i - 1][j] == '.') dist[i][j][i - 1][j] = dist[i - 1][j][i][j] = 1;
            if(j && grid[i][j - 1] == '.') dist[i][j - 1][i][j] = dist[i][j][i][j - 1] = 1;
            if(j < w - 1 && grid[i][j + 1] == '.') dist[i][j + 1][i][j] = dist[i][j][i][j + 1] = 1;
            if(i < h - 1 && grid[i + 1][j] == '.') dist[i + 1][j][i][j] = dist[i][j][i + 1][j] = 1;
        }
    }

    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) {
            for(ll k = 0; k < h; ++k) {
                for(ll l = 0; l < w; ++l) {
                    if(i == k && j == l && grid[i][j] != '#') continue;
                    if(!dist[i][j][k][l]) dist[i][j][k][l] = LONG_LONG_MAX;
                }
            }
        }
    }

    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) {
            for(ll k = 0; k < h; ++k) {
                for(ll l = 0; l < w; ++l) {
                    for(ll a = 0; a < h; ++a) {
                        for(ll b = 0; b < w; ++b) {
                            if(grid[a][b] == '#' || grid[k][l] == '#' || grid[i][j] == '#') continue;
                            if(dist[k][l][a][b] == LONG_LONG_MAX || dist[a][b][i][j] == LONG_LONG_MAX) continue;
                            dist[i][j][k][l] = dist[k][l][i][j] = min(dist[i][j][a][b] + dist[a][b][k][l], dist[k][l][i][j]);
                        }
                    }
                }
            }
        }
    }

    /*for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) cout << dist[0][0][i][j] << ' ';
        cout << '\n';
    }*/

    ll ans = 0;
    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) {
            for(ll k = 0; k < h; ++k) {
                for(ll l = 0; l < w; ++l) {
                    if(dist[i][j][k][l] != LONG_LONG_MAX) ans = max(ans, dist[i][j][k][l]);
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}