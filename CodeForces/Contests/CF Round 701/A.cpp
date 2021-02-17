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
ll t, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;

        ll ans = LLONG_MAX;
        for(ll i = max(2ll, b); (i - 1) * (i - 1) <= a; ++i) {
            ll cnt = 0, cur = a;
            while(cur) {
                cur /= i;
                cnt++;
            }

            ans = min(ans, i - b + cnt);
        }
        
        if(b * b - 1 >= a) ans = min(ans, 2ll);
        if(b > a) ans = min(ans, 1ll);
        cout << ans << '\n';
    }

    return 0;
}