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
ll t, n, a[507], b[507];
map<pair<ll, ll>, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) cin >> b[i];

        occ.clear();
        for(ll i = 0; i < n/2; ++i) {
            if(a[i] > a[n - i - 1]) swap(a[i], a[n - i - 1]);
            occ[{a[i], a[n - i - 1]}]++;
        }

        for(ll i = 0; i < n/2; ++i) {
            if(b[i] > b[n - i - 1]) swap(b[i], b[n - i - 1]);
            occ[{b[i], b[n - i - 1]}]--;
        }

        bool ok = 1;
        for(auto i : occ) {
            if(i.second) {
                ok = 0;
                break;
            }
        }

        if(n%2 == 1 && a[n/2] != b[n/2]) ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}