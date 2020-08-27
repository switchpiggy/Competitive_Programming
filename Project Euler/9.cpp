#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;

        ll ans = INT_MIN;
        for(ll a = 1; a <= n/3; ++a) {
            ll b = (n * n - 2 * n * a)/(2 * n - 2 * a);
            ll c = n - a - b;
            cout << a << ' ' << b << ' ' << c << endl;
            if(a * a + b * b == c * c && a < b && b < c && a && b && c) {
                ans = max(ans, a * b * c);
            }
        } 

        if(ans == INT_MIN) ans = -1;
        cout << ans << endl;
    }

    return 0;
}