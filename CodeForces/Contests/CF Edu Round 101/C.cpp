#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k, h[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) cin >> h[i];

        ll prev = h[0];
        //cout << prev << ' ';
        bool ok = 1;
        for(ll i = 1; i < n - 1; ++i) {
            if(h[i] >= prev + k || h[i] + 2 * k - 1 <= prev) {
                ok = 0;
                break;
            }

            //if(i == n - 1) break;
            if(h[i + 1] > h[i]) {
                prev = max(max(prev - k + 1, h[i]), min(h[i] + k - 1, prev + k - 1));
            } else {
                prev = min(max(prev - k + 1, h[i]), min(h[i] + k - 1, prev + k - 1));
            }
            //cout << prev << ' ';
        }

        if(h[n - 1] >= prev + k || h[n - 1] <= prev - k) ok = 0;

        cout << (ok ? "YES\n" : "NO\n");
    }
}