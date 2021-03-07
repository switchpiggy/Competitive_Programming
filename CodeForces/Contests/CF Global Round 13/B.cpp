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
ll t, n, u, v, a[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> u >> v;
        for(ll i = 1; i <= n; ++i) cin >> a[i];
        a[0] = a[1];
        a[n + 1] = a[n];

        ll ans = u + v; 
        for(ll i = 1; i <= n; ++i) {
            if(abs(a[i] - a[i - 1]) > 1 || abs(a[i] - a[i + 1]) > 1) {
                ans = 0;
                break;
            }

            if(a[i] == a[i - 1] && a[i] == a[i + 1]) {
                ans = min(ans, 2 * v);
            } else {
                ans = min(ans, u);
                ans = min(ans, v);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}