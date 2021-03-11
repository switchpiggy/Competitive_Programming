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
ll t, n;
ll x, y;
vector<ll> a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    flout;
    cin >> t;
    while(t--) {
        a.clear();
        b.clear();
        cin >> n;
        for(ll i = 0; i < 2 * n; ++i) {
            cin >> x >> y;
            if(!x) a.push_back(abs(y));
            else b.push_back(abs(x));
        }

        sort(all(a));
        sort(all(b));

        ld ans = 0;
        for(ll i = 0; i < n; ++i) {
            ans += sqrt((ld)a[i] * (ld)a[i] + (ld)b[i] * (ld)b[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}