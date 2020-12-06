#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[5007];

ll solve(ll l, ll r) {
    ll mins = INT_MAX, ans = 0;
    for(ll i = l ; i <= r; ++i) mins = min(mins, a[i]);
    ans = mins;
    ll prev = -1;
    for(ll i = l; i <= r; ++i) {
        a[i] -= mins;
        if(a[i] > 0) {
            if(prev == -1) prev = i;
        } else {
            if(prev != -1) ans += solve(prev, i - 1);
            prev = -1;
        }
    }

    if(prev != -1) ans += solve(prev, r);

    return min(ans, r - l + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    cout << solve(0, n - 1) << '\n';
    return 0;
}