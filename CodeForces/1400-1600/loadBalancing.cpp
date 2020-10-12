#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> m[i];
        sum += m[i];
    }

    ll average = sum/n;

    sort(m, m + n);

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(sum%n && i >= n - sum%n) ans += abs(m[i] - average - 1);
        else ans += abs(m[i] - average);
    }

    cout << ans/2 << '\n';
    return 0;
}