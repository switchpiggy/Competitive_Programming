#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, m;
long double a[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; ++i) a[i] += a[i - 1];

    //sort(a + 1, a + n + 1);

    long double ans = 0;
    for(ll i = 0; i <= min(m, n - 1); ++i) {
        ans = max(ans, (a[n] - a[i] + min((long double)(m - i), (long double)(n - i) * (long double)k))/(long double)(n - i));        
    }

    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}