#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
long double n, r, x[1007], ans[1007];

int main() {
    cin >> n >> r;

    for(ll i = 0; i < (ll)n; ++i) cin >> x[i];

    for(ll i = 0; i < (ll)n; ++i) {
        long double res = r;
        for(ll j = 0; j < i; ++j) {
            if(abs(x[i] - x[j]) > 2 * r) continue;
            long double y = sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j]));

            res = max(res, y + ans[j]);
        }

        ans[i] = res;
    }

    for(ll i = 0; i < (ll)n; ++i) cout << fixed << setprecision(7) << ans[i] << ' ';
    cout << '\n';
    return 0;
}