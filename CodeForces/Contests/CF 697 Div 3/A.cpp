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
ll t, n, pow2[57];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    pow2[0] = 1;
    for(ll i = 1; i <= 50; ++i) pow2[i] = pow2[i - 1] * 2;
    while(t--) {
        cin >> n;
        bool ok = 0;
        for(ll i = 0; i <= 50; ++i) {
            if(pow2[i] == n) {
                ok = 1;
                break;
            }
        }

        cout << (ok ? "NO\n" : "YES\n");
    }

    return 0;
}