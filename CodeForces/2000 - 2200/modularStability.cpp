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
ll n, k, fact[500007];

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll rec = fastpow(x, y/2);
    if(y%2) return rec * rec%MOD * x%MOD;
    return rec * rec%MOD;
}

ll inv(ll x) {
    return fastpow(x, MOD - 2);
}

ll choose(ll x, ll y) {
    return (fact[x] * inv(fact[x - y])%MOD * inv(fact[y])%MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fact[0] = 1;
    for(ll i = 1; i <= 500000; ++i) fact[i] = (fact[i - 1] * i)%MOD;

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        if(n/i - 1 >= k - 1) {
            ans = (ans + choose(n/i - 1, k - 1))%MOD;
        }
    }

    cout << ans << '\n';
    return 0;
}