#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    if(n == 1) {
        cout << 1 << ' ' << 1 << '\n' << 0 << '\n' << 1 << ' ' << 1 << '\n' << 0 << '\n' << 1 << ' ' << 1 << '\n' << 0 - a[1] << '\n';
        return 0;
    }

    cout << 1 << ' ' << n - 1 << '\n';
    for(ll i = 1; i <= n - 1; ++i) {
        ll cur = 0;
        if(a[i] < 0) {
            cur += (n - 1) * ((abs(a[i]) + (n - 1) - 1)/(n - 1));
            a[i] += cur;
        }

        cur += (n - 1) * (a[i]%n);
        a[i] += (n - 1) * (a[i]%n);
        cout << cur << ' ';
    }

    cout << '\n';

    cout << n << ' ' << n << '\n' << 0 - a[n] << '\n';
    a[n] = 0;

    cout << 1 << ' ' << n << '\n';
    for(ll i = 1; i <= n; ++i) cout << 0 - a[i] << ' ';
    return 0;
}