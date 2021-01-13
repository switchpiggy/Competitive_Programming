#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, k, a, b;

ll lcm(ll x, ll y) {
    return y/__gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a >> b;
    ll mins = LLONG_MAX, maxs = LLONG_MIN;

    ll s = a, t = k - a;
    for(ll i = 0; i < n; ++i) {
        ll xx = k * i + b, yy = k * i - b;
        ll x = xx, y = yy;
        //cout << x << ' ' << y << ' ' << i << '\n';
        if(x <= s) x += n * k;
        if(y <= s) y += n * k;
        if(xx <= t) xx += n * k;
        if(yy <= t) yy += n * k;
        //cout << x << ' ' << y << ' ' << i << '\n';

        if(xx != t)  {
            mins = min(mins, lcm(abs(xx - t), n * k));
            maxs = max(maxs, lcm(abs(xx - t), n * k));
        } else {
            mins = 1;
            maxs = max(maxs, 1ll);
        }

        if(yy != t) {
            mins = min(mins, lcm(abs(yy - t), n * k));
            maxs = max(maxs, lcm(abs(yy - t), n * k));
        } else {
            mins = 1;
            maxs = max(maxs, 1ll);
        }

        if(x != s) {
            mins = min(mins, lcm(abs(x - s), n * k));
            maxs = max(maxs, lcm(abs(x - s), n * k));
        } else {
            mins = 1;
            maxs = max(maxs, 1ll);
        }

        if(y != s) {
            mins = min(mins, lcm(abs(y - s), n * k));
            maxs = max(maxs, lcm(abs(y - s), n * k));
        } else {
            mins = 1;
            maxs = max(maxs, 1ll);
        }
    }

    cout << mins << ' ' << maxs << '\n';
    return 0;
}