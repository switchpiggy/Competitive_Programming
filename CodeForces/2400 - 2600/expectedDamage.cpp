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
ll n, m, d[200007], a, b, p[200007];

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll rec = fastpow(x, y/2);
    if(y%2) return ((rec * rec)%MOD * x)%MOD;
    return (rec * rec)%MOD;
}

ll inv(ll x) {
    return fastpow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> d[i];
    sort(d, d + n);
    for(ll i = n - 1; i >= 0; --i) p[i] = (p[i + 1] + d[i])%MOD;

    while(m--) {
        cin >> a >> b;
        ll cnt = n - (lower_bound(d, d + n, b) - d);
        // cout << cnt << '\n';
        cout << ((p[n - cnt] * (max(0ll, cnt - a)%MOD * inv(cnt)%MOD)%MOD)%MOD + ((p[0] - p[n - cnt] + MOD)%MOD * (max(0ll, cnt - a + 1)%MOD * inv(cnt + 1)%MOD)%MOD)%MOD)%MOD << '\n';
    }

    return 0;
}