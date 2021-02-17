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
ll n, m, k, t, p[200007], r[200007];
vector<pair<ll, pair<ll, ll>>> v;

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);

    if(x == y) return;
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);

    p[x] = y;
    return;
}

ll kruskal() {
    sort(all(v));

    ll res = 0;
    for(ll i = 0; i < sz(v); ++i) {
        pair<ll, ll> j = v[i].second;
        if(get(j.first) == get(j.second)) continue;
        res += v[i].first;
        uni(j.first, j.second);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> m >> k;
        m0(r);
        iota(p + 1, p + n + 1, 1);

        ll ans = INF;
        for(ll i = 0; i < m; ++i) {
            ll x, y, s;
            cin >> x >> y >> s;
            v.push_back({max(0ll, s - k), {x, y}});
            if(s <= k) {
                //ans = min(ans, abs(k - s));
                uni(x, y);
            }
            ans = min(ans, abs(k - s));
        }

        for(ll i = 1; i < n; ++i) {
            if(get(i) != get(i + 1)) {
                ans = INF;
                break;
            } 
        }

        if(ans != INF) {
            cout << ans << '\n';
            continue;
        }

        m0(r);
        iota(p + 1, p + n + 1, 1);
        cout << kruskal() << '\n';
        //for(pair<ll, pair<ll, ll>> i : v) cout << i.first << ' ' << i.second.first << ' ' << i.second.second << '\n';
    }

    return 0;
}