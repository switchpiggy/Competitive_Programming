#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n, greater<ll>());

    for(ll i = 1; i <= n; ++i) {
        ll res = 0, cur = 0;

        for(ll j = n - 1; j >= n - n%i; --j) res += max(0ll, a[j] - n/i);

        for(ll j = 0; j < n - n%i; ++j) {
            if(j%i == 0 && j) cur++;
            res += max(0ll, a[j] - cur);
        }

        if(res >= m) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}