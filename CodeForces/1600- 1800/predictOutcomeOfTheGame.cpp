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
ll t;
ll n, k, d1, d2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> d1 >> d2;
        bool ok = 0;
        for(ll i = -1; i <= 1; i += 2) {
            for(ll j = -1; j <= 1; j += 2) {
                ll x = d1 * i, y = d2 * j;
                if(k < 2 * x + y || (k - (2 * x + y))%3 != 0) continue;
                ll k1 = (k - (2 * x + y))/3, k2 = k1 + x, k3 = k2 + y;
                if(k1 + k2 + k3 != k || k1 < 0 || k2 < 0 || k3 < 0 || max({k1, k2, k3}) > n/3) continue;
                if(n - k < x + 2 * y || (n - k - (x + 2 * y))%3 != 0) continue;
                //cout << k1 << ' ' << k2 << ' ' << k3 << ' ' << n/3 << '\n';
                ok = 1;
                break;
            }

            if(ok) break;
        }

        cout << (ok ? "yes\n" : "no\n");
    }

    return 0;
}