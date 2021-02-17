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
ll n, w[27], x;
pair<ll, ll> dp[(1 << 21)];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = {1, 0};
    cin >> n >> x;
    for(ll i = 0; i < n; ++i) cin >> w[i];

    for(ll i = 1; i < (1 << n); ++i) {
        dp[i] = {n + 1, 0};
        for(ll j = 0; j < n; ++j) {
            if(i & (1 << j)) {
                pair<ll, ll> res = dp[i - (1 << j)];
                if(res.second + w[j] <= x) {
                    res.second += w[j];
                } else {
                    res.first++;
                    res.second = w[j];
                }

                dp[i] = min(dp[i], res);
            }
        }
    }

    cout << dp[(1 << n) - 1].first << '\n';
    return 0;
}