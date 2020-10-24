#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], ans[1007][1007], occ[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n * n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    /*if(n == 2) {
        ll two = 0, four = 0;
        for(ll i = 1; i <= 1000; ++i) {
            if(occ[i] == 2) two++;
            if(occ[i] == 4) four++;
        }

        if(two == 2) {
            for(ll i = 1; i <= 1000; ++i) {
                if(occ[i]) {
                    cout << i << ' ' << i << '\n';
                }
            }
        } else if(four == 1) {
            for(ll i = 1; i <= 1000; ++i) {
                if(occ[i]) {
                    cout << i << ' ' << i << '\n' << i << ' ' << i << '\n';
                }
            }
        } else cout <<  "no\n";

        return 0;
    }*/

    if(n%2 == 0) {
        ll r = 1, c = 1;
        for(ll i = 1; i <= 1000; ++i) {
            if(occ[i]%4 != 0) {
                cout << "NO\n";
                return 0;
            }
        }

        for(ll i = 1; i <= 1000; ++i) {
            while(occ[i]) {
                ans[r][c] = ans[n - r + 1][c] = ans[n - r + 1][n - c + 1] = ans[r][n - c + 1] = i;
                occ[i] -= 4;
                c++;
                if(c == n/2 + 1) {
                    r++;
                    c = 1;
                }
            }
        }

        cout << "yes\n";
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) cout << ans[i][j] << ' ';
            cout << '\n';
        }

        return 0;
    }

    ll one = 0, two = 0, three = 0;
    for(ll i = 1; i <= 1000; ++i) {
        if(occ[i]%4 == 1) {
            ans[n/2 + 1][n/2 + 1] = i;
            one++;
            occ[i]--;
        }
        if(occ[i]%4 == 2) two++;
        if(occ[i]%4 == 3) {
            ans[n/2 + 1][n/2 + 1] = i;
            three++;
            occ[i]--;
        }
    }

    if(one + three != 1) {
        cout << "NO\n";
        return 0;
    } 

    if(two + three > n - 1 || (two + three)%2 == 1) {
        cout << "NO\n";
        return 0;
    }

    ll r = 1, c = 1, midRow = 1, midCol = 1, step = 1;
    for(ll i = 1; i <= 1000; ++i) {
        if(occ[i]%4 == 2) {
            if(step == 1) {
                ans[n/2 + 1][midRow] = ans[n/2 + 1][n - midRow + 1] = i;
                midRow++;
            } else {
                ans[midCol][n/2 + 1] = ans[n - midCol + 1][n/2 + 1] = i;
                midCol++;
            }

            occ[i] -= 2;
            step = 1 - step;
        }
    }

    for(ll i = 1; i <= 1000; ++i) {
            while(occ[i]) {
                ans[r][c] = ans[n - r + 1][c] = ans[n - r + 1][n - c + 1] = ans[r][n - c + 1] = i;
                if(c == n - c + 1) {
                    ans[c][r] = ans[c][n - r + 1] = i;
                }
                if(r == n - r + 1) {
                    ans[c][r] = ans[n - c + 1][r] = i;
                }
                while(ans[r][c]) {
                    c++;
                    if(c > n/2 + 1) {
                        r++;
                        c = 1;
                    }
                }

                occ[i] -= 4;
            }
    }

    cout << "yes\n";
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) cout << ans[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}