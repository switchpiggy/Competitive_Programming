#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, sx, sy, fx, fy;

int main() {
    cin >> n >> m >> k;
    for(ll i = 0; i < k; ++i) cin >> sx >> sy;
    for(ll i = 0; i < k; ++i) cin >> fx >> fy;

    cout << (n - 1) + (m - 1) + (n * m) - 1 << endl;

    for(ll i = 0; i < n - 1; ++i) cout << "U";
    for(ll i = 0; i < m - 1; ++i) cout << "L";
    for(ll i = 1; i <= m; ++i) {
        for(ll j = 1; j <= n - 1; ++j) {
            if(i%2 == 1) cout << "D";
            else cout << "U";
        }
        if(i < m) cout << "R"; 
    }

    return 0;
}