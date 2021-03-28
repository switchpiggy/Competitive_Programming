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
ll t, rr, c, a[1007][1007], u[1007][1007], d[1007][1007], r[1007][1007], l[1007][1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(ll tc = 1; tc <= t; ++tc) {
        cin >> rr >> c;
        for(ll i = 0; i < rr; ++i) {
            for(ll j = 0; j < c; ++j) cin >> a[i][j];
        }

        for(ll i = 0; i < rr; ++i) {
            ll cnt = 0;
            for(ll j = 0; j < c; ++j) {
                if(a[i][j] == 1) cnt++;
                else cnt = 0;
                l[i][j] = cnt;
            }

            cnt = 0;
            for(ll j = c - 1; j >= 0; --j) {
                if(a[i][j] == 1) cnt++;
                else cnt = 0;
                r[i][j] = cnt;
            }
        }

        for(ll i = 0; i < c; ++i) {
            ll cnt = 0;
            for(ll j = 0; j < rr; ++j) {
                if(a[j][i] == 1) cnt++;
                else cnt = 0;
                u[j][i] = cnt;
            }

            cnt = 0;
            for(ll j = rr - 1; j >= 0; --j) {
                if(a[j][i] == 1) cnt++;
                else cnt = 0;
                d[j][i] = cnt;
            }
        }

        ll ans = 0;
        for(ll i = 0; i < rr; ++i) {
            for(ll j = 0; j < c; ++j) {
                if(!a[i][j]) {
                    // cout << "0 ";
                    continue;
                }
                ll x[2] = {l[i][j], r[i][j]}, y[2] = {u[i][j], d[i][j]}, res = 0;
                for(ll k = 0; k < 2; ++k) {
                    for(ll q = 0; q < 2; ++q) {
                        ll maxn = x[k], minn = y[q];
                        res += min(maxn/2, minn) - (maxn >= 2 && minn >= 1) + min(minn/2, maxn) - (minn >= 2 && maxn >= 1);
                    }
                }

                ans += res;
                // cout << res << ' ';
            }

            // cout << '\n';
        }

        cout << "Case #" << tc << ": ";
        cout << ans << '\n';
    }

    return 0;
}