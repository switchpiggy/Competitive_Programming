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
ll t, n, m, a[100007], occ[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        m0(occ);
        for(ll i = 0; i < n; ++i) cin >> a[i], occ[a[i]%m]++;

        ll ans = 0;
        for(ll i = 1; m - i > i; ++i) {
            ll x = occ[i], y = occ[m - i];
            if(x || y) {
                if(x && y) {
                    ans++;
                    ll mins = min(x, y);
                    x -= mins, y -= mins;
                    if(x) x--;
                    if(y) y--;
                }   

                ans += x + y;
            }
        }

        if(occ[0]) ans++;
        if(m%2 == 0 && occ[m/2]) ans++;

        cout << ans << '\n';
    }

    return 0;
}