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
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, m, f[2000007];

ll inv(ll x, ll y) {
    if(!y) return 1;
    ll rec = inv(x, y/2);
    if(y%2) return ((rec * rec)%MOD * x)%MOD;
    return (rec * rec)%MOD;
}

ll choose(ll x, ll y) {
    return ((f[x] * inv(f[x - y], MOD - 2)%MOD) * inv(f[y], MOD - 2))%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    f[0] = 1;
    for(ll i = 1; i <= 2000000; ++i) f[i] = (f[i - 1] * i)%MOD;

    ll ans = 0;
    for(ll i = 1; i <= m; ++i) {
        ll cur = i, ans2 = 1;

        for(ll j = 2; j * j <= cur; ++j) {
            if(cur%j) continue;

            ll cnt2 = 0;
            while(!(cur%j)) {
                cnt2++;
                cur /= j;
            }

            (ans2 *= choose(cnt2 + n - 1, n - 1)) %= MOD;
            // cout << i << ' ' << j << ' ' << cnt2 + n - 1 << ' ' << n - 1 << ' ' << choose(cnt2 + n - 1, n - 1) << '\n';
        }
        
        if(cur > 1) (ans2 *= choose(n, n - 1)) %= MOD;
        // cout << ans2 << '\n';
        (ans += ans2) %= MOD;
    }

    cout << ans << '\n';
    return 0;
}