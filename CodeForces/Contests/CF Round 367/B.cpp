#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x[100007], q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> x[i];
    sort(x, x + n);

    cin >> q;
    while(q--) {
        ll m;
        cin >> m;
        ll cur = upper_bound(x, x + n, m) - x;
        cout << max(0ll, cur) << '\n';
    }

    return 0;
}