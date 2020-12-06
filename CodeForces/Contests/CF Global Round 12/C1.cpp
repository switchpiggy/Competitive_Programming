#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
ll t, n;
char a[307][307], b[307][37];
/* 
bool up(ll x, ll y) {
    if(x + 1 < n && x + 2 < n && a[x + 1][y] == 'X' && a[x + 2][y] == 'X') return 1;
    return 0;
}
 
bool down(ll x, ll y) {
    if(x - 1 >= 0 && x - 2 >= 0 && a[x - 1][y] == 'X' && a[x - 2][y] == 'X') return 1;
    return 0;
}
 
bool left(ll x, ll y) {
    if(y - 1 >= 0 && y - 2 >= 0 && a[x][y - 1] == 'X' && a[x][y - 2] == 'X') return 1;
    return 0;
}
 
bool right(ll x, ll y) {
    if(y + 1 < n && y + 2 < n && a[x][y + 1] == 'X' && a[x][y + 2] == 'X') return 1;
    return 0;
}
 
bool midHor(ll x, ll y) {
    if(y + 1 < n && y - 1 >= 0 && a[x][y - 1] == 'X' && a[x][y + 1] == 'X') return 1;
    return 0;
}
 
bool midVer(ll x, ll y) {
    if(x + 1 < n && x - 1 >= 0 && a[x - 1][y] == 'X' && a[x + 1][y] == 'X') return 1;
    return 0;
}*/
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
 
        ll cnt = 0;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                cin >> a[i][j];
                b[i][j] = a[i][j];
                cnt += (a[i][j] == 'X');
            }
        }
 
        ll maxn = cnt/3;
        ll d = 0;

        for(ll i = 1; i < n; i += 3) {
            for(ll j = 0; j < n - i; ++j) {
                if(a[j][j + i] == 'X') {
                    a[j][j + i] = 'O';
                    d++;
                }
            }
        }

        for(ll i = 2; i < n; i += 3) {
            for(ll j = i; j < n; ++j) {
                if(a[j][j - i] == 'X') {
                    a[j][j - i] = 'O';
                    d++;
                }
            }
        }

        if(d <= maxn) {
            for(ll i = 0; i < n; ++i, cout << '\n') {
                for(ll j = 0; j < n; ++j) cout << a[i][j];
            }

            continue;
        }

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) a[i][j] = b[i][j];
        }

        d = 0;
        for(ll i = 2; i < n; i += 3) {
            for(ll j = 0; j < n - i; ++j) {
                if(a[j][j + i] == 'X') {
                    a[j][j + i] = 'O';
                    d++;
                }
            }
        }

        for(ll i = 1; i < n; i+= 3) {
            for(ll j = i; j < n; ++j) {
                if(a[j][j - i] == 'X') {
                    a[j][j - i] = 'O';
                    d++;
                }
            }
        }
        
        if(d <= maxn) {
        for(ll i = 0; i < n; ++i, cout << '\n') {
            for(ll j = 0; j < n; ++j) cout << a[i][j];
        }
        continue;
        }

        d = 0;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) a[i][j] = b[i][j];
        }

        for(ll i = 0; i < n; i += 3) {
            for(ll j = 0; j < n - i; ++j) {
                if(a[j][j + i] == 'X') {
                    a[j][j + i] = 'O';
                    d++;
                }
            }
        }

        for(ll i = 3; i < n; i += 3) {
            for(ll j = i; j < n; ++j) {
                if(a[j][j - i] == 'X') {
                    a[j][j - i] = 'O';
                    d++;
                }
            }
        }

        if(d <= maxn) {
            for(ll i = 0; i < n; ++i, cout << '\n') {
                for(ll j = 0; j < n; ++j) cout << a[i][j];
            }
        }
    }
 
    return 0;
} 