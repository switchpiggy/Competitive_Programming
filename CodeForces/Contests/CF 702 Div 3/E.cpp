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
ll t, n;
vector<pair<ll, ll>> v;

bool check(ll x) {
    ll cur = v[x].first;
    for(ll i = 0; i < n; ++i) {
        if(i == x) continue;
        if(v[i].first > cur) return 0;
        cur += v[i].first;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            v.push_back({x, i});
        }

        sort(all(v));

        ll l = 0, r = n, ans = 0;
        while(l < r) {
            ll mid = (l + r)/2;
            if(check(mid)) {
                ans = mid;
                r = mid;
            } else l = mid + 1;
        }

        //cout << ans << '\n';
        vector<ll> res;
        for(ll i = 0; i < n; ++i) if(v[i].first >= v[ans].first) res.push_back(v[i].second + 1);

        sort(all(res));

        cout << sz(res) << '\n';
        for(ll i : res) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}