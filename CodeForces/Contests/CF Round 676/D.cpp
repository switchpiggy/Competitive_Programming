#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x, y, c1, c2, c3, c4, c5,c6;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> x >> y >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        ll ans = 0, up = min(c6, c1 + c5), down = min(c3, c2 + c4), r = min(c1 + c3, c2), l = min(c5, c4 + c6);
        ll ru = c1, ld = c4;
        if(ru < r + up && x >= 0 && y >= 0) {
            ll cur = min(x, y);
            x -= cur;
            y -= cur;
            ans += cur * ru;
        }

        if(ld < l + down && x < 0 && y < 0) {
            ll cur = min(abs(x), abs(y));
            x += cur;
            y += cur;
            ans += cur * ld;
        }
        
        if(y <= 0) ans += abs(y) * l;
        else ans += abs(y) * r;
        
        if(x <= 0) ans += abs(x) * down;
        else ans += abs(x) * up;

        cout << ans << '\n';
    }

    return 0;
}