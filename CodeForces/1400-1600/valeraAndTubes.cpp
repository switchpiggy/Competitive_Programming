#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k;
bool visited[307][307];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    ll r = 1, c = 1, dir = 1;
    for(ll i = 0; i < k - 1; ++i) {
        cout << 2 << ' ';
        if(dir == 1) {
            if(c < m) {
                visited[r][c] = visited[r][c + 1] = 1;
                cout << r << ' ' << c << ' ' << r << ' ' << c + 1 << '\n';
                c += 2;
                if(c > m) {
                    c = m;
                    r++;
                    dir = 1 - dir;
                }
            } else {
                visited[r][c] = visited[r + 1][c] = 1;
                cout << r << ' ' << c << ' ' << r + 1 << ' ' << c << '\n';
                r++;
                c--;
                dir = 1 - dir;
            }
        } else {
            if(c > 1) {
                visited[r][c] = visited[r][c - 1] = 1;
                cout << r << ' ' << c << ' ' << r << ' ' << c - 1 << '\n';
                c -= 2;
                if(c < 1) {
                    c = 1;
                    r++;
                    dir = 1 - dir;
                }
            } else {
                visited[r][c] = visited[r + 1][c] = 1;
                cout << r << ' ' << c << ' ' << r + 1 << ' ' << c << '\n';
                r++;
                c++;
                dir = 1 - dir;
            }
        }
    }

    dir = 1;
    cout << n * m - (2 * (k - 1)) << ' ';
    for(ll i = 1; i <= n; ++i) {
       if(dir) {
           for(ll j = 1; j <= m; ++j) if(!visited[i][j]) cout << i << ' ' << j << ' ';
       } else {
           for(ll j = m; j >= 1; --j) if(!visited[i][j]) cout << i << ' ' << j << ' ';
       }

       dir = 1 - dir;
    }

    return 0;
}