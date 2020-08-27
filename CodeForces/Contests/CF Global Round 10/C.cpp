#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[200007];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        ll res = 0;
        ll prev = a[0], cur = 0;
        for(ll i = 1; i < n; ++i) {
            if(a[i] >= prev) {
                prev = a[i];
                cur = 0;
            } else {
                ll temp = max(0ll, prev - a[i] - cur);
                res += temp;
                cur = prev - a[i];
            }
        }

        cout << res << endl;
    }

    return 0;
}