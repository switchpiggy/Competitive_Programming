#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, l, r, m;

int main() {
    cin >> t;
    while(t--) {
        cin >> l >> r >> m;
        for(ll i = l; i <= r; ++i) {

            ll n = (m + r - l)/i;

            if(n * i <= m + r - l && n * i >= m + l - r) {
                ll b = l, c = l + m - (n * i);
                if(c < l) {
                    b += l - c;
                    c = l;
                }

                cout << i << ' ' << c << ' ' << b << endl;
                break;
            }
        }
    }

    return 0;
}