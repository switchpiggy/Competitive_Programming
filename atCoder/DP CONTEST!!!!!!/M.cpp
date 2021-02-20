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
ll n, k, a[107], dp[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    dp[k] = 1;
    for(ll i = 0; i < n; ++i) {
        vector<ll> pref(k + 1);
        for(ll j = k; j >= 0; --j) {
            ll c = dp[j];
            ll r = j - 1, l = max(0ll, j - a[i]);
            if(l <= r) {
                (pref[l] += c + MOD) %= MOD;
                if(r + 1 <= k) (pref[r + 1] -= c + MOD) %= MOD;
            }
        }

        for(ll j = 0; j <= k; ++j) { 
            if(j) (pref[j] += pref[j - 1] + MOD) %= MOD;
            (dp[j] += pref[j] + MOD) %= MOD;
        }
    }

    cout << dp[0] << '\n';
}