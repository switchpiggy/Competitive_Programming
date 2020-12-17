#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a[57], n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) {
            ll cur = 1, res = 1;
            while(cur <= 1e9) {
                if(abs(a[i] - cur) < abs(a[i] - res)) res = cur;
                cur *= 2;
            }

            cout << res << ' ';
        }

        cout << '\n';
    }
}