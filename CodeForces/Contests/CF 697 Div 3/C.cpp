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
ll t, a[200007], b[200007], x, y, k, occ[200007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        m0(occ);
        cin >> x >> y >> k;
        for(ll i = 0; i < k; ++i) {
            cin >> a[i];
            occ[a[i]][0]++;
        }
        for(ll i = 0; i < k; ++i) {
            cin >> b[i];
            occ[b[i]][1]++;
        }

        ll ans = 0;
        for(ll i = 0; i < k; ++i) {
            ans += k - ((occ[a[i]][0] - 1) + (occ[b[i]][1] - 1)) - 1;            
        }

        cout << ans/2 << '\n';
    }

    return 0;
}