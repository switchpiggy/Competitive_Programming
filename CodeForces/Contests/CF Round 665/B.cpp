#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, c, d, e, f;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d >> e >> f;
        ll sum = 0;
        ll profit = min(c, e);
        sum += 2 * profit;
        c -= profit;
        e -= profit;

        ll loss = max(0ll, f - a - c);
        sum -= 2 * min(loss, b);

        cout << sum << endl;
    }

    return 0;
}