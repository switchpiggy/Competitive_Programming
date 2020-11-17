#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;
ll t;
long double d;
long double MINS = 0.000000000001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> d;
        if(d == 0) {
            cout << "Y " << 0 << ' ' << 0 << '\n';
            continue;
        }

        long double ans = -1;
        long double l = 0, r = d;
        while(r - l >= MINS) {
            long double m = (l + r)/2;
            //cout << m << ' ';
            if(d/(d - m) - m > MINS) {
                l = m + MINS;
            } else if(m - d/(d - m) > MINS) {
                r = m;
            } else {
                ans = m;
                break;
            }
        }

        if(ans == -1) cout << "N\n";
        else cout << "Y " << fixed << setprecision(12) << ans << ' ' << d - ans << '\n';
    }

    return 0;
}