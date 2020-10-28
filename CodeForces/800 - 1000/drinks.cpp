#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long double ans = 0;
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> p[i];

    for(ll i = 0; i < n; ++i) {
        ans += (long double)p[i];
    }

    ans /= (long double)n;

    cout << fixed << setprecision(5) << ans << '\n';
    return 0;
}