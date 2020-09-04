#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n, a, x, y, b, k, arr[200007];

ll lcm(ll x, ll y) {return (x * y)/(__gcd(x, y));}

bool check(ll mid) {
    ll i = mid/lcm(a, b), j = mid/a - i, l = mid/b - i;

    ll ans = 0, it = 0;
    for(it = 0; it < i && it < mid; ++it) ans += arr[it] * (x + y);
    for(it = i; it < i + l && it < mid; ++it) ans += arr[it] * y;
    for(it = i + l; it < i + l + j && it < mid; ++it) ans += arr[it] * x;

    if(ans/100 >= k) return 1;
    return 0;
}

int main() {
    cin >> q;
    while(q--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr + n, greater<ll>());

        cin >> x >> a >> y >> b >> k;

        if(x > y) {
            swap(a, b);
            swap(x, y);
        } else if(x == y && a > b) {
            swap(a, b);
        }

        ll l = 1, r = n + 1, ans = -1;
        while(l < r) {
            ll mid = (l + r)/2;
            if(check(mid)) {
                ans = mid;
                r = mid;
            } else l = mid + 1;
        }

        cout << ans << endl;
    }

    return 0;
}