#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
char a[57][57], res[107][107];
bool atk[57][57];
vector<pair<ll, ll>> v;

bool in(ll x, ll y) {
    return (x < n && x >= 0 && y < n && y >= 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll r, c;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) cin >> a[i][j];
    }

    for(ll i = -1 * n + 1; i < n; ++i) {
        for(ll j = -1 * n + 1; j < n; ++j) {
            if(i == j && j == 0) continue;
            bool ok = 1;
            for(ll k = 0; k < n; ++k) {
                for(ll l = 0; l < n; ++l) {
                    if(a[k][l] == 'o' && in(k + i, l + j) && a[k + i][l + j] == '.') {
                        ok = 0;
                        break;
                    }
                    if(!ok) break;
                }
            }

            if(!ok) continue;
            v.push_back({i, j});
            for(ll k = 0; k < n; ++k) {
                for(ll l = 0; l < n; ++l) {
                    if(a[k][l] == 'o' && in(k + i, l + j)) atk[k + i][l + j] = 1;
                }
            }
        }
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(!atk[i][j] && a[i][j] == 'x') {
                cout << "NO\n";
                return 0;
            }
        }
    }

    for(ll i = 0; i < (ll)v.size(); ++i) {
        res[n + v[i].first][n + v[i].second] = 'x';
    }

    cout << "YES\n";
    for(ll i = 1; i < 2 * n; ++i, cout << '\n') {
        for(ll j = 1; j < 2 * n; ++j) {
            if(j == n && i == n) cout << 'o';
            else if(res[i][j] == 'x') cout << 'x';
            else cout << '.';
        }
    }

    return 0;
}