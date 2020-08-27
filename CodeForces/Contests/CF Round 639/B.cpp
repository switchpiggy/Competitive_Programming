#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;

        ll res = 0;
        while(n > 1) {
            ll l = 1, r = n, cur = -1;
            while(l <= r) {
                ll m = (l + r)/2;
                if(2 * m + (3 * (m * (m - 1))/2) > n) r = m - 1;
                else if(2 * m + (3 * (m * (m - 1))/2) < n) {
                    cur = m;
                    l = m + 1;
                } else {
                    cur = m;
                    break;
                }
            }

            //cout << l << ' ' << r << endl;

            n -= 2 * cur + (3 * (cur * (cur - 1))/2);
            res++;
        }

        cout << res << endl;
    }

    return 0;
}