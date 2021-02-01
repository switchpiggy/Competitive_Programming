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
ll m, x, y, c[107];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    for(ll i = 0; i < m; ++i) cin >> c[i];
    cin >> x >> y;

    for(ll i = 1; i <= m; ++i) {
        ll a = 0,b = 0;
        for(ll j = 0; j < m; ++j) {
            if(j + 1 >= i) b += c[j];
            else a += c[j];
        }

        if(a >= x && a <= y && b >= x && b <= y) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}