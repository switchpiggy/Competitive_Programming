#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[57], t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;

        ll sum = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if(sum != 0) {
            cout << "YES\n";
            if(sum > 0) sort(a, a + n, greater<ll>());
            else sort(a, a + n);
            ll cnt = 0;
            for(ll i = 0; i < n; ++i) {
                if(a[i] == 0) {
                    cnt++;
                    continue;
                }

                cout << a[i] << ' ';
            }

            for(ll i = 0; i < cnt; ++i) cout << 0 << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}