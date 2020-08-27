#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans = INT_MAX;

int main() {
    cin >> n;
    for(ll i = 1; i <= 162; ++i) {
        ll l = 0, r = 1e9;
        ll res = -1;
        while(l <= r) {
            ll m = (l + r)/2;
            if((m * m) + (i * m) <= n) {
                l = m + 1;
                res = m;
            }
            else r = m - 1;
        }

        if(res != -1 && (res * res) + (i * res) == n) {
            ll sum = 0, k = res;
            while(k) {
                sum += k%10;
                k /= 10;
            }

            if(sum == i) ans = min(ans, res);
        }
    }

    if(ans == INT_MAX) ans = -1;

    cout << ans << endl;
    return 0;
}