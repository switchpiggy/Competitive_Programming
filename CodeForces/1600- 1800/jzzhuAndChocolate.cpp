#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    if(k > n + m - 2) {
        cout << "-1\n";
        return 0;
    }

    ll ans = -1;
    if(k + 1 <= n) ans = max(ans, m * (n/(k + 1)));
    else ans = max(ans, m/(k - n + 2));
    if(k + 1 <= m) ans = max(ans, n * (m/(k + 1)));
    else ans = max(ans, n/(k - m + 2));

    cout << ans << '\n';
    return 0;
}