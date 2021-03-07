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
ll t, n, m;
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        occ.clear();
        cin >> n >> m;
        occ[n + 1] = 3;
        for(ll i = 0; i < m; ++i) {
            ll r, c;
            cin >> r >> c;
            occ[c] |= (1 << (r - 1));
        }

        ll last = -1;
        bool ok = 1;
        for(auto i : occ) {
            if(last == -1) {
                if(i.second == 3) last = -1;
                else last = (i.first + i.second)%2;
            } else {
                if(i.second == 3) {
                    ok = 0;
                    break;
                }

                if(last == (i.first + i.second)%2) {
                    ok = 0;
                    break;
                }

                last = -1;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}