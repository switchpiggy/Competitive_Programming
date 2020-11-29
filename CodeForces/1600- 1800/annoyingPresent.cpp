#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
long double x, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    long double ans = 0;
    ll res = 0;
    for(ll i = 1; i <= n; ++i) {
        res += abs(i - (n + 1)/2);
    }
    for(ll i = 0; i < m; ++i) {
        cin >> x >> d;
        ans += n * x;
        if(d >= 0) ans += (n * (n - 1))/2 * d;
        else ans += d * (long double)res;
    }

    cout << fixed << setprecision(12) << ans/(long double)n << '\n';
    return 0;
}