#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

ll sum(ll x) {
    return (x * (x + 1))/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    ll l = 0, r = k, ans = LONG_LONG_MIN;
    while(l < r) {
        ll mid = (l + r)/2;
        if(sum(k - 1) - sum(k - 1 - mid) < n) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if(ans == LONG_LONG_MIN || ((sum(k - 1) - sum(k - 1 - ans))< n - 1 - (k - 1 - ans))) {
        cout << "-1\n";
        return 0;
    }

    cout << ans + (sum(k - 1) - sum(k - 1 - ans) < n - 1) << '\n';
    return 0;
}