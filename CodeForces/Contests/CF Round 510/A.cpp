#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    ll maxn = 0;
    for(ll i = 0; i < n; ++i) maxn = max(maxn, a[i]);
    cout << max(maxn, (sum + m)/n + ((sum + m)%n > 0)) << ' ' << maxn + m << '\n';
    return 0;
}