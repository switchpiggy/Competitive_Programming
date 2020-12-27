#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x;

ll sqr(ll x) {
    ll s = sqrt(x);
    for(ll i = -2; i <= 2; ++i) {
        if(s + i >= 0 && (s + i) * (s + i) == x) return s;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x;
        bool ok = 0;
        for(ll i = 1; i <= 40000; ++i) {
            if(i * i <= x) continue;
            
            ll k = i/sqr(i * i - x);
            if(sqr(i * i - x) <= 0) continue;

            if(k > 0 && i * i - (i/k) * (i/k) == x) {
                cout << i << ' ' << k << '\n';
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "-1\n";
    }
}