#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], ans[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);

    if(a[n] >= a[n - 1] + a[n - 2]) {
        cout << "NO\n";
        return 0;
    }

    for(ll i = 0; i < n/2; ++i) {
        ans[i] = a[n - 2 * i];
        ans[n - i - 1] = a[n - 2 * i - 1];
    }

    if(n%2 == 1) {
        ans[n/2] = a[1];
    }

    for(ll i = 0; i < n; ++i) {
        if(ans[i] >= ans[(i - 1 + n)%n] + ans[(i + 1)%n]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}