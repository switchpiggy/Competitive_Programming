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
#define flout cout << fixed << setprecision(12)
ll x, y, n;

bool larger(ll a, ll b, ll c, ll d) {
    return a * d >= b * c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y >> n;
    ll a = 0, b = n;
    for(ll i = 1; i <= n; ++i) {
        ll l = 0, r = 1e12, ans = -1;
        while(l < r) {
            ll mid = (l + r)/2;
            if(larger(mid, i, x, y)) {
                ans = mid;
                r = mid;
            } else l = mid + 1;
        }

        if(larger(abs(a * y - x * b), b * y, abs(ans * y - x * i), i * y)) a = ans, b = i;
        if(larger(abs(a * y - x * b), b * y, abs((ans - 1) * y - x * i), i * y)) a = ans - 1, b = i;
    }

    cout << a/__gcd(a, b) << '/' << b/__gcd(a, b) << '\n';
    return 0;
}