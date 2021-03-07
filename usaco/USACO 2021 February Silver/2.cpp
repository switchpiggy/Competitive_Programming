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
ll n, k, a[100007];
bool last[100007];
vector<pair<ll, ll>> v, res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    for(ll i = 0; i < n; ++i) {
        v.push_back({a[i]/12 * 12, (a[i] + 11)/12 * 12});
    }

    sort(all(v));
    for(ll i = 0; i < n; ++i) {
        if(!i || v[i] != v[i - 1]) res.push_back(v[i]);
    }

    // for(pair<ll, ll> i : res) cout << i.first << ' ' << i.second << '\n';

    vector<pair<ll, pair<ll, ll>>> diff;
    sort(all(res));
    for(ll i = 0; i < sz(res) - 1; ++i) {
        diff.push_back({res[i + 1].first - res[i].second, {i, i + 1}});
    }

    sort(all(diff));
    ll ans = 0, mins = diff[0].first, g = sz(res);
    for(ll i = 0; i < max(0ll, sz(res) - k); ++i) {
        g--;
        ans += diff[i].first;
        if(i + 1 < sz(diff)) mins = diff[i + 1].first;
        else mins = INF;
    }

    //for(ll i = 0; i < sz(res); ++i) cout << last[i] << ' ';

    //either walk back, or make one more merge
    // for(ll i = 0; i < sz(res); ++i) {
        // if(last[i]) {
            // ans1 = res[i].first; 
            // break;
        // }
    // }

    //if(sz(res) - (k - 1) < sz(diff)) ans1 = min(ans1, diff[sz(res) - (k - 1)].first);

    for(pair<ll, ll> i : res) ans += i.second - i.first;

    if(g < k) {
        cout << ans << '\n';
        return 0;
    }

    // cout << mins << ' ' << res[0].first << '\n';
    cout << ans + min(mins, res[0].first) << '\n';
    return 0;
}