#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        ll sum = 0, sum2 = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            sum += (a[i] + x - 1)/x;
            sum2 += a[i];
        }

        cout << (sum2 + x - 1)/x << ' ' << sum << '\n';
    }

    return 0;
}