#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, x, y, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> b >> x >> y >> n;
        if(a > b) {
            swap(a, b);
            swap(x, y);
        } else if(a == b && x > y) {
            swap(a, b);
            swap(x, y);
        }

        ll c = min(n, abs(a - x));
        ll d = min(n - c, abs(b - y));

        ll ans = 0;
        ans = (a - c) * (b - d);

        ll e = min(n,  abs(b - y));
        ll f = min(n - e, abs(a - x));

        cout << min(ans, (b - e) * (a - f)) << endl;
    }

    return 0;
}