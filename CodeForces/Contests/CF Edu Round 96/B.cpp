#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n, greater<ll>());

        ll sum = a[0];

        for(ll i = 1; i < k + 1 && i < n; ++i) {
            sum += a[i];
        }

        cout << sum << '\n';
    }

    return 0;
}