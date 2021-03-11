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
ll k, t, l, r, x, y;
bool v[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> l >> r >> t >> x >> y;
    if(x >= y) {
        if(t == 1) cout << (k + (k + y <= r ? y : 0) - x >= l ? "Yes\n" : "No\n");
        else cout << ((x - y) <= (k + (k + y <= r ? y : 0) - l - x)/(t - 1) ? "Yes\n" : "No\n");
        return 0;
    }

    if(k + y <= r) k += y;

    bool ok = 1;
    while(t) {
        if(k - x < l) {
            ok = 0;
            break;
        }

        ll cnt = min(t, (k - l)/x);
        k -= cnt * x;
        t -= cnt;

        if(k + y <= r) {
            k += y;
            if(v[k%x]) {
                break;
            }

            v[k%x] = 1;
        } else if(t) {
            ok = 0;
            break;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}