#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[27], b[27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);

    if(a[n - 1] > b[n - 1]) {
        cout << "0\n";
        return 0;
    }

    ll ans = 1;
    for(ll i = n - 1; i >= 0; --i) {
        ll cur = 0;
        for(ll j = n - 1; j >= 0; --j) {
            if(a[i] <= b[j]) cur++;
            else break;
        }

        ans *= cur - (n - 1 - i);
    }

    cout << ans << '\n';
    return 0;
}