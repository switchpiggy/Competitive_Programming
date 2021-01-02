#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, z, x[200007];

bool check(ll a) {
    for(ll i = 1; i <= a; ++i) {
        if(x[n - a + i] < x[i] + z) return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> z;
    for(ll i = 1; i <= n; ++i) cin >> x[i];
    
    sort(x + 1, x + n + 1);

    ll l = 0, r = n/2 + 1, ans = 0;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << ans << '\n';
    return 0;
}