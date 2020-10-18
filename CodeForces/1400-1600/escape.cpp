#include <bits/stdc++.h>
using namespace std;

typedef long double ll;
ll vp, vd, t, f, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> vp >> vd >> t >> f >> c;

    if(vp >= vd) {
        cout << 0 << '\n';
        return 0;
    }

    ll cur = t * vp, res = 0;
    while(1) {
        if(cur >= c) break;
        ll cur2 = cur + vp * (cur/(vd - vp));
        if(cur2 >= c) break;
        res++;

        cur = cur2 + (cur2/vd + f) * vp;
    }

    cout << res << '\n';
    return 0;
}