#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
long double t, h, c;
ll tc;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--) {
        cin >> h >> c >> t;
        ll l = 0, r = 1000000000;
        ll ans = 2;
        while(l < r) {
            ll m = (l + r)/2;
            if(check(m) < check(ans)) ans = m;
            if(check(m) > t) {
                l = m + 1;
            } else r = m;
        }

        cout << ans << '\n';
    }

    return 0;
}