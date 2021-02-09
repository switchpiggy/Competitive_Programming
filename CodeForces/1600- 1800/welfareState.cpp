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
ll n, a[200007], q, t, p, x, last[200007];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll cur = 0;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    cin >> q;
    while(q--) {
        cur++;
        cin >> t;
        if(t == 1) {
            cin >> p >> x;
            a[p] = x;
            last[p] = cur;
        } else {
            cin >> x;
            v.push_back({cur, x});
        }
    }

    sort(all(v));
    for(ll i = sz(v) - 2; i >= 0; --i) {
        v[i].second = max(v[i].second, v[i + 1].second);
    }

    for(ll i = 1; i <= n; ++i) {
        ll k = upper_bound(all(v), make_pair(last[i], -1ll)) - v.begin();
        if(k != sz(v)) {
            a[i] = max(a[i], v[k].second);
        }
    }

    for(ll i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}