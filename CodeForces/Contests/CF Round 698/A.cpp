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
ll t, n, a[107], occ[107];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        m0(occ);
        cin >> n;
        ll ans = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            occ[a[i]]++;
            ans = max(ans, occ[a[i]]);
        }

        cout << ans << '\n';
    }
}