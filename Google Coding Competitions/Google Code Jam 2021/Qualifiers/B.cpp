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
ll t, x, y, dp[1007][2];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(ll tc = 1; tc <= t; ++tc) {
        cin >> x >> y >> s;
        inf(dp);

        if(s[0] == 'C') dp[0][0] = 0;
        else if(s[0] == 'J') dp[0][1] = 0;
        else dp[0][0] = dp[0][1] = 0;

        for(ll i = 0; i < sz(s); ++i) {
            if(s[i] == 'C') {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + x);
            } else if(s[i] == 'J') {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][1]);
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + y);
            } else {
                dp[i + 1][0] = min({dp[i][0], dp[i][1] + y, dp[i + 1][0]});
                dp[i + 1][1] = min({dp[i + 1][1], dp[i][1], dp[i][0] + x});
            }
        }

        /*if(sz(s) == 4) {
            for(ll i = 0; i <= 4; ++i, cout << '\n') {
                for(ll j = 0; j < 2; ++j) cout << dp[i][j] << ' ';
            }
        }*/

        ll ans = INF;
        if(s.back() == 'C') ans = dp[sz(s) - 1][0];
        else if(s.back() == 'J') ans = dp[sz(s) - 1][1];
        else ans = min(dp[sz(s) - 1][0], dp[sz(s) - 1][1]);
        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}