#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, d, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> x >> y >> d;
        if(abs(x - y)%d != 0 && abs(y)%d != 1 && abs(n - y)%d != 0) {
            cout << "-1\n";
            continue;
        }

        ll ans = INT_MAX;
        if(abs(x - y)%d == 0) ans = min(ans, abs(x - y)/d);
        if(abs(n - y)%d == 0) ans = min(ans, (abs(n - x) + d - 1)/d + abs(n - y)/d);
        if(abs(y)%d == 1) ans = min(ans, (x - 1 + d - 1)/d + (y - 1)/d);

        cout << ans << '\n';
    }

    return 0;
}