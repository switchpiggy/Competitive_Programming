#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll t, n, k, a, b, c, d;

bool check(ll cur, ll x, ll y, ll z) {
    ll maxn = 0;
    for(ll i = 1; i <= n; ++i) {
        if(cur < i * x) continue;
        if(cur >= i * x + i * y) maxn = max(maxn, i * y + (cur - i * x - i * y)/2);
        else maxn = max(maxn, cur - i * x);
    }

    return z + maxn >= k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> a >> b >> c >> d;
        if(a > c) {
            swap(a, c);
            swap(b, d);
        }

        ll l = 0, r = 1e18, ans = 1e18;
        ll x = max(0ll, c - b), y, z;
        if(b < c) {
            z = 0;
            y = d - a;
        } else {
            y = max(b, d) - min(b, d) + max(a, c) - min(a, c); 
            if(b >= d) z = n * (d - c);
            else z = n * (b - c);
        }

        if(z >= k) {
            cout << "0\n";
            continue;
        }

        while(l < r) {
            ll mid = (l + r)/2;
            if(check(mid, x, y, z)) {
                r = mid;
                ans = mid;
            } else l = mid + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}