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
ll t, n, u, r, d, l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> u >> r >> d >> l;
        bool ok = 0;
        for(ll i = 0; i < 4; ++i) {
            for(ll j = 0; j < 4; ++j) {
                ll x = (i & 1) + ((i & 2) > 0);
                ll y = (j & 1) + ((j & 2) > 0);
                if(x > u || y > d || u - x > n - 2 || d - y > n - 2) continue;
                ll k1 = ((i & 1) > 0) + ((j & 1) > 0), k2 = ((i & 2) > 0) + ((j & 2) > 0);
                // cout << k1 << ' ' << k2 << '\n';
                if(k1 <= l && k2 <= r && l - k1 <= n - 2 && r - k2 <= n - 2) {
                    //cout << i << ' ' << j << '\n';
                    ok = 1;
                    break;
                }
            }

            if(ok) break;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}