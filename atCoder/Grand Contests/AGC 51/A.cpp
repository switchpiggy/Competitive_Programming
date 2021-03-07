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
ll d;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll rec = fastpow(x, y/2);
    if(y%2) return((rec * rec)%MOD * x)%MOD;
    return (rec * rec)%MOD;
}

ll ncr(ll x, ll y) {
    ll ans = 1;
    for(ll i = 1; i <= y; ++i) {
        (ans *= x - i + 1) %= MOD;
        (ans *= fastpow(i, MOD - 2)) %= MOD;
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> d;

    cout << (ncr(2 * d, d) * fastpow(2, MOD - 2))%MOD << '\n';
    return 0;
}