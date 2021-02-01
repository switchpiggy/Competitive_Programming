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
#define INF 0x3f3f3f3f3f3f3f3f
#define flout cout << fixed << setprecision(12)
ll a[14], b[14];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 0; i < 14; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    for(ll i = 0; i < 14; ++i) {
        if(!a[i]) continue;
        for(ll j = 0; j < 14; ++j) b[j] = a[j];

        b[i] = 0;
        for(ll j = 1; j <= 14; ++j) {
            b[(i + j)%14] += a[i]/14;
        }

        for(ll j = 1; j <= a[i]%14; ++j) {
            b[(i + j)%14]++;
        }

        ll res = 0;
        //b[i] = 0;
        for(ll j = 0; j < 14; ++j) if(b[j]%2 == 0) res += b[j];

        ans = max(ans, res);
        //if(res == 53580) {
        //    for(ll j = 0; j < 14; ++j) cout << b[j] << ' ';
        //    cout << '\n';
        //}
    }

    cout << ans << '\n';
    return 0;
}