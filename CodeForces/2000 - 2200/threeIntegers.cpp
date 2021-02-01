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
ll t, a, b, c;
vector<ll> fact[20007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[1].push_back(1);
    for(ll i = 2; i <= 20000; ++i) {
        for(ll j = 1; j * j <= i; ++j) {
            if(i%j == 0) {
                fact[i].push_back(j);
                if(i/j != j) fact[i].push_back(i/j);
            }
        }
    }

    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        ll ans = LLONG_MAX, A = -1, B = -1, C = -1;
        for(ll i = 1; i <= 20000; ++i) {
            ll res = abs(b - i);
            if(c < i) res += (i - c);
            else res += min(c%i, i - c%i);

            ll cur = LLONG_MAX;
            for(ll j : fact[i]) {
                cur = min(cur, abs(a - j));
            }

            res += cur;
            if(res < ans) {
                ans = res;
                B = i;
                if(c < i) C = i;
                else if(c%i < i - c%i) C = c - c%i;
                else C = c + (i - c%i);

                if(a - cur > 0 && i%(a - cur) == 0) A = a - cur;
                else A = a + cur;
            }
        }

        cout << ans << '\n' << A << ' ' << B << ' ' << C << '\n';
    }

    return 0;
}