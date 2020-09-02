#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, row[52], col[52];

int main() {
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            ll temp;
            cin >> temp;
            if(temp == 1) {
                row[i]++;
                col[j]++;
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ans += (ll)pow(2, row[i]) - 1 + (ll)pow(2, m - row[i]) - 1; 
    }
    for(ll i = 0; i < m; ++i) {
        ans += (ll)pow(2, col[i]) - 1 + (ll)pow(2, n - col[i]) - 1;
    }

    cout << ans - n * m << endl;
    return 0;
}