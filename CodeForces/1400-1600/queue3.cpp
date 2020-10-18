#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], mins[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    mins[n - 1] = a[n - 1];
    for(ll i = n - 2; i >= 0; --i) {
        mins[i] = min(mins[i + 1], a[i]);
    }

    for(ll i = 0; i < n; ++i) {
        ll res = -1;
        ll l = i + 1, r = n;

        while(l < r) {
            ll m = (l + r)/2;
            if(mins[m] < a[i] && (mins[m + 1] >= a[i] || m + 1 >= n)) {
                res = m;
                l = m + 1;
            } else if(mins[m] >= a[i]) r = m;
            else l = m + 1;
        }

        if(res != -1) cout << res - i - 1 << ' ';
        else cout << -1 << ' ';
    }

    return 0;
}