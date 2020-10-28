#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        for(ll i = 0; i < n; ++i) {
            if(i < n/2) cout << a[n - 1 - i] << ' ';
            else cout << -1 * a[n - 1 - i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}