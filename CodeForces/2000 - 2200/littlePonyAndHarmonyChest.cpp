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
ll n, a[107], dp[107][(1 << 17)], f[61];
ll p[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inf(dp);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = 0; i < 17; ++i) {
        for(ll j = 1; j < 60; ++j) {
            if(j%p[i] == 0) f[j] |= (1 << i);
        }
    }

    //vector<ll> v;
    dp[0][0] = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 1; j < 60; ++j) {
            ll k = f[j]^((1 << 17) - 1);
            for(ll m = k; ; m = (m - 1) & k) {
                dp[i + 1][f[j]|m] = min(dp[i + 1][f[j]|m], dp[i][m] + abs(j - a[i]));
                if(!m) break;
            }
        }
    }

    ll ans = INF, last;
    for(ll i = 0; i < (1 << 17); ++i) {
        if(dp[n][i] < ans) {
            ans = dp[n][i];
            last = i;
        }
    }

    //cout << ans << ' ' << last << '\n';

    vector<ll> v;
    for(ll i = n - 1; i >= 0; --i) {
        for(ll j = 1; j < 60; ++j) {
            bool ok = 0;
            ll k = ((1 << 17) - 1)^f[j];
            for(ll m = k; ; m = (m - 1) & k) {
                if(dp[i + 1][last] == dp[i][m] + abs(j - a[i]) && (m|f[j]) == last) {
                    v.push_back(j);
                    ok = 1;
                    last = m;
                    break;
                }

                if(!m) break;
            }

            if(ok) break;
        }
    }

    reverse(all(v));
    for(ll i : v) cout << i << ' ';
    cout << '\n';
    //cout << ans << '\n';
    return 0;
}