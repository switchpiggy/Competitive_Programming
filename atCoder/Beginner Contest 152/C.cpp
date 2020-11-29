#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    ll mins = INT_MAX, ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(a[i] < mins) ans++;
        mins = min(mins, a[i]);
    }

    cout << ans << '\n';
    return 0;
}