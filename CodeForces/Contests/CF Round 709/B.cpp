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
ll t, n, a[100007], cnt[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        if(n <= 2) {
            cout << "0\n";
            continue;
        }
        
        ll inc = -1;
        for(ll i = 0; i < n - 1; ++i) {
            if(a[i + 1] >= a[i]) {
                inc = a[i + 1] - a[i];
                break;
            }
        }

        if(inc == -1) {
            bool ok = 1;
            ll dec = a[0] - a[1];
            for(ll i = 0; i < n - 1; ++i) {
                if(a[i] - a[i + 1] != dec) {
                    ok = 0;
                    break;
                }
            }

            cout << (ok ? "0\n" : "-1\n");
            continue;
        }

        if(!inc) {
            bool ok = 1;
            for(ll i = 0; i < n - 1; ++i) if(a[i + 1] != a[i]) {
                ok = 0;
                break;
            }
            cout << (ok ? "0\n" : "-1\n");
            continue;
        }

        bool ok = 1;
        for(ll i = 0; i < n - 1; ++i) {
            if(a[i] <= a[i + 1] && a[i] + inc != a[i + 1]) {
                ok = 0;
                break;
            }
        }

        if(!ok) {
            cout << "-1\n";
            continue;
        }

        ll m = -1;
        for(ll i = 0; i < n - 1; ++i) {
            if(a[i] > a[i + 1]) {
                m = a[i] - a[i + 1] + inc;
                break;
            }
        }

        if(m == -1) {
            cout << "0\n";
            continue;
        }

        if(a[0] >= m) {
            cout << "-1\n";
            continue;
        }

        ok = 1;
        ll cur = a[0];
        for(ll i = 1; i < n; ++i) {
            (cur += inc) %= m;
            if(cur != a[i]) {
                ok = 0;
                break;
            }
        }

        if(!ok) cout << "-1\n";
        else cout << m << ' ' << inc << '\n';
    }

    return 0;
}