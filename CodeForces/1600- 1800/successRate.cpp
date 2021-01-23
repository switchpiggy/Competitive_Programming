#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
ll t, x, y, p, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x >> y >> p >> q;
        ll l = 0, r = 1e9 + 1, ans = -1;
        while(l < r) {
            ll mid = (l + r)/2;
            if(q * mid >= y && x + (q * mid - y) >= p * mid && x <= p * mid) {
                ans = mid;
                r = mid;
            } else  {
                l = mid + 1;
            }
        }

        if(ans != -1) cout << ans * q - y << '\n';
        else cout << ans << '\n';
    }

    return 0;
}