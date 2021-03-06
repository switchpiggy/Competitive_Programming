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
ll t;
string a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        reverse(all(a));
        reverse(all(b));

        ll res = -1, res1 = -1;
        for(ll i = 0; i < sz(b); ++i) {
            if(b[i] == '1') {
                res = i;
                break;
            }
        }

        for(ll i = max(0ll, res); i < sz(a); ++i) {
            if(a[i] == '1') {
                res1 = i;
                break;
            }
        }

        if(res1 == -1 || res == -1) cout << "0\n";
        else cout << res1 - res << '\n';
    }

    return 0;
}