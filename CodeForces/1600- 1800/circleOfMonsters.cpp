#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define LONG_LONG_MAX 9223372036854775807;

ll t, n, a[300007], b[300007], res[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;

        ll sum = 0, res = LONG_LONG_MAX;

        for(ll i = 0; i < n; ++i) cin >> a[i] >> b[i];

        for(ll i = 0; i < n; ++i) {
            sum += a[(i + 1)%n] - min(a[(i + 1)%n], b[i]);
            res = min(res, min(a[(i + 1)%n], b[i])); 
        }

        cout << res + sum << '\n';
    }

    return 0;
}