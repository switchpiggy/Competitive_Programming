#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, n, m, t, r, l;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> x >> m;
        ll curL = 0, curR = 0;

        bool ok = 0;
        for(ll i = 0; i < m; ++i) {
            cin >> l >> r;
            if(ok) {
                if((curL <= l && l <= curR) || (curL <= r && r <= curR) || (l <= curL && curR <= r)) {
                    curL = min(curL, l);
                    curR = max(curR, r);
                }
            } else if(l <= x && x <= r) {
                ok = 1;
                curL = l;
                curR = r;
            }
        }

        cout << curR - curL + 1 << endl;
    }

    return 0;
}