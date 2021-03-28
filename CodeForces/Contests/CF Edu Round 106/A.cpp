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
ll t, k1, k2, w, bb, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k1 >> k2 >> w >> bb;
        ll a = 0, b = 0, a1 = 0, b1 = 0;
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= 2; ++j) {
                if(i%2 == j%2) {
                    if((j == 1 && i <= k1) || (j == 2 && i <= k2)) a++;
                    else a1++;
                } else {
                    if((j == 1 && i <= k1) || (j == 2 && i <= k2)) b++;
                    else b1++;
                }   
            }
        }

        // cout << a << ' ' << b << ' ' << a1 << ' ' << b1 << ' ' << w << ' ' << b << '\n';
        if((min(a, b) >= w && min(a1, b1) >= bb)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}