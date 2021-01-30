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
ll t, n, a[200007], b[200007], d[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        //m0(a);
        cin >> n;
        for(ll i = 0; i < 2 * n; ++i) cin >> a[i];
        sort(a, a + 2 * n, greater<ll>());

        bool ok = 1;
        for(ll i = 0; i < n; ++i) {
            if(a[i * 2] != a[i * 2 + 1]) {
                cout << "NO\n";
                ok = 0;
                break;
            }

            b[i] = a[i * 2];
        }

        if(!ok) continue;

        for(ll i = 1; i < n; ++i) {
            if(b[i] == b[i - 1] || (b[i - 1] - b[i])%(2 * (n - i))) {
                cout << "NO\n";
                ok = 0;
                break;
            }

            d[i] = (b[i - 1] - b[i])/(2 * (n - i));
        }

        if(!ok) continue;

        for(ll i = 1; i < n; ++i) {
            b[n - 1] -= 2 * i * d[i];
        }

        if(b[n - 1] <= 0 || b[n - 1]%(2 * n)) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}