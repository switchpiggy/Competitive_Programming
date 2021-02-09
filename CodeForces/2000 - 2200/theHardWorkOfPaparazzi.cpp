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
ll n, r, dp[1000007], pref[1000007];
vector<pair<ll, pair<ll, ll>>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> n;
    v.push_back({0, {1, 1}});
    for(ll i = 0; i < n; ++i) {
        ll t, x, y;
        cin >> t >> x >> y;
        v.push_back({t, {x, y}});
    }

    //cout << n << '\n';
    for(ll i = 0; i < n + 1; ++i) {
        if(!dp[i] && i) {
            pref[i] = pref[i - 1];
            if(i + 2 * r - 1 < n + 1) dp[i + 2 * r - 1] = max(dp[i + 2 * r - 1], pref[i] + 1);
            continue;
        }
        for(ll j = i + 1; j < min(n + 1, i + 2 * r - 1); ++j) {
            if(v[j].first - v[i].first >= abs(v[j].second.first - v[i].second.first) + abs(v[j].second.second - v[i].second.second)) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        
        if(i) pref[i] = max(pref[i - 1], dp[i]);
        if(i + 2 * r - 1 < n + 1) dp[i + 2 * r - 1] = max(dp[i + 2 * r - 1], pref[i] + 1);
    }

    ll ans = 0;
    for(ll i = 0; i < n + 1; ++i) ans = max(ans, dp[i]);
    cout << pref[n] << '\n';
    //cout << ans << '\n';
    return 0;
}