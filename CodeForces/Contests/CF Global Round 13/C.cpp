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
ll t, n, a[5007], in[5007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        m0(in);
        for(ll i = 0; i < n; ++i) cin >> a[i];
        ll ans = 0;
        for(ll i = 0; i < n; ++i) {
            //if(a[i] == 1) continue;
            ll x = in[i];
            //cout << in[i] << ' ';
            if(x < a[i] - 1) {
                ans += a[i] - 1 - x;
                x += a[i] - 1 - x;
            }

            in[i + 1] += x - (a[i] - 1);
            for(ll j = 2; j <= a[i] && i + j < n; ++j) {
                in[i + j]++;
            }
        }

        //for(ll i = 0; i < n; ++i) cout << a[i] << ' ';

        cout << ans << '\n';
    }

    return 0;
}