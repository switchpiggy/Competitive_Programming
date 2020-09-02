#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, x[300007], p[300007];

int main() {
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> x[i];
    for(ll i = 0; i < m; ++i) cin >> p[i];

    ll gcf = x[1] - x[0];
    for(ll i = 2; i < n; ++i) {
        gcf = __gcd(gcf, x[i] - x[i - 1]);
    }

    for(ll i = 0; i < m; ++i) {
        if(gcf%p[i] == 0) {
            cout << "YES" << endl << x[0] << ' ' << i + 1 << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}