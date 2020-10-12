#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[57][57], b[57][57];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; 
    for(ll i = 0; i <= 56; ++i) {
        for(ll j = 0; j <= 56; ++j) a[i][j] = b[i][j] = INT_MAX;
    }
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> a[i][j];
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> b[i][j];
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
        }
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(a[i][j] >= a[i][j + 1] || a[i][j] >= a[i + 1][j] || b[i][j] >= b[i][j + 1] || b[i][j] >= b[i + 1][j]) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    cout << "Possible\n";
    return 0;
}