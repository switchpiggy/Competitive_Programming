#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ll res = INT_MAX;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        res = min(res, b - a + 1);
    }

    cout << res << '\n';
    for(ll i = 1; i <= n; ++i) cout << i%res << ' ';
    cout << '\n';

    return 0;
}