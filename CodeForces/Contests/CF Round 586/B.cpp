#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m[1007][1007], res[1007];

ll _gcd(ll x, ll y) {
    if(!x) return y;
    if(!y) return x;
    return __gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) cin >> m[i][j];
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(m[i][j] == 0) continue;
            for(ll k = 1; k <= n; ++k) {
                if(m[i][k] == 0 || m[j][k] == 0) continue;
                res[i] = (m[i][j] * m[i][k])/m[j][k];
                break;
            }

            break;
        }
    }

    for(ll i = 1; i <= n; ++i) cout << (ll)sqrt(res[i]) << ' ';
    
    return 0;
}