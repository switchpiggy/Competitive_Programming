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
ll t, c, d, x, cnt[20000007];

ll solve(ll x, ll y) {
    if(y%x) return 0;
    ll z = y/x, res = 0;
    for(ll i = 2; i * i <= z; ++i) {
        if(z%i == 0) res++;
        while(z%i == 0) {
            z /= i;
        }

        if(z <= 20000000) return (1 << (cnt[z] + res));
    }

    return (1 << (cnt[z] + res));
}

void sieve() {
    for(ll i = 2; i <= 20000000; ++i) {
        if(cnt[i]) continue;
        for(ll j = i; j <= 20000000; j += i) cnt[j]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cin >> t;
    while(t--) {
        cin >> c >> d >> x;
        ll ans = 0;
        for(ll i = 1; i * i <= x; ++i) {
            if(x%i == 0) {
                if((x + d * i)%c == 0) ans += solve(i, (x + d * i)/c);
                if(x/i != i && (x + d * (x/i))%c == 0) ans += solve(x/i, (x + d * (x/i))/c);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}