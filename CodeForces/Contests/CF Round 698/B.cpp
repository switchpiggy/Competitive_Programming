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
ll t, q, d, a[10007], u[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> q >> d;

        for(ll i = 0; i < q; ++i) {
            cin >> a[i];
            bool ok = 0;
            ll units = a[i]%10;
            for(ll j = 0; j < 10; ++j) {
                if((j * 10 + units)%d == 0 && j * 10 + units <= a[i] && j * 10 + units > 0) {
                    ok = 1;
                    break;
                }
            }

            string s = to_string(a[i]);
            for(char i : s) {
                if(i - '0' == d) {
                    ok = 1;
                    break;
                }
            }

            if(!ok && a[i]/d > 10) ok = 1;
            cout << (ok ? "YES\n" : "NO\n");
        }
    }

    return 0;
}