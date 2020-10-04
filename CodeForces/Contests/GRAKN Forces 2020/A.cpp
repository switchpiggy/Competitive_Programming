#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[107], b[107], c[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) cin >> b[i];
        for(ll i = 0; i < n; ++i) cin >> c[i];

        ll cur = a[0];
        cout << cur << ' ';
        for(ll i = 1; i < n - 1; ++i) {
            if(a[i] != cur) {
                cout << a[i] << ' ';
                cur = a[i];
            } else if(b[i] != cur) {
                cout << b[i] << ' ';
                cur = b[i];
            } else {
                cout << c[i] << ' ';
                cur = c[i];
            }
        }

        if(a[n - 1] != cur && a[n - 1] != a[0]) cout << a[n - 1] << ' ';
        else if(b[n - 1] != cur && b[n - 1] != a[0]) cout << b[n - 1] << ' ';
        else cout << c[n - 1] << ' ';

        cout << '\n';
    }

    return 0;
}