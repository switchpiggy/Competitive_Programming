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
ll t, n, m, pref[100007];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> m;
        for(ll i = 0; i < m; ++i) {
            ll a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }

        sort(all(v));

        pref[0] = v[0].first;
        for(ll i = 1; i < m; ++i) {
            pref[i] = pref[i - 1] + v[i].first;
        }

        ll ans = 0;
        for(ll i = 0; i < m; ++i) {
            ll k = upper_bound(all(v), make_pair(v[i].second, -1ll)) - v.begin();
            k = max(k, m - n + 1);
            ans = max(ans, pref[m - 1] - (k ? pref[k - 1] : 0) + (n - (m - k) - 1) * v[i].second + (k <= i ? v[i].second : v[i].first));
        }

        cout << ans << '\n';
    }

    return 0;
}