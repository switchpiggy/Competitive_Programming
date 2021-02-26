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
ll n, dp[3007], s[3007], c[3007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> s[i];
    for(ll i = 1; i <= n; ++i) cin >> c[i];

    ll ans = INF;
    for(ll i = n; i >= 1; --i) {
        ll cur = 0;
        for(ll j = i + 1; j <= n; ++j) {
            if(s[j] > s[i] && (!cur || c[j] < c[cur])) cur = j;
        }

        dp[i] = cur;
        for(ll j = i + 1; j <= n; ++j) {
            if(s[j] > s[i] && dp[j]) ans = min(ans, c[dp[j]] + c[j] + c[i]);
        }
    }

    if(ans == INF) ans = -1;
    cout << ans << '\n';
    return 0;
}