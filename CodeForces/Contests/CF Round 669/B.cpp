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
ll t, n, a[1007], cnt[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        //m0(cnt);
        ll maxn = 0;
        for(ll i = 0; i < n; ++i) cin >> a[i], maxn = max(maxn, a[i]);

        ll cur = maxn;
        for(ll i = 0; i < n; ++i) {
            ll res = -1;
            for(ll j = 0; j < n; ++j) {
                if(a[j] == -1) continue;
                if(res == -1 || __gcd(a[j], cur) > __gcd(a[res], cur)) {
                    res = j;
                }
            }

            cout << a[res] << ' ';
            //a[res] = -1;
            cur = __gcd(cur, a[res]);
            a[res] = -1;
        }

        cout << '\n';
    }

    return 0;
}