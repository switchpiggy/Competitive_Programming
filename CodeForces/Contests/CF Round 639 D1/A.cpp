#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m0(x) memset(x, 0, sizeof(x))
#define m1(x) memset(x, 1, sizeof(x))
#define mn1(x) memset(x, -1, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll t, n, a[200007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        occ.clear();
        for(ll i = 0; i < n; ++i) cin >> a[i];
        ll maxn = 0;
        for(ll i = 0; i < n; ++i) {
            occ[(i + a[i] + 1000000000)%n]++;
            //maxn = max(maxn, occ[(i + a[i])%n]);
        }

        bool ok = 1;
        for(ll i = 0; i < n; ++i) {
            if(occ[i] != 1) {
                ok = 0;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}