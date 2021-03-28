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
ll n, m, a, b, c, p[100007], r[100007];
vector<pair<ll, pair<ll, ll>>> e;

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

bool uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(x == y) return 0;

    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;
    return 1;
}

ll mst() {
    sort(all(e));
    ll ans = 0;
    for(auto i : e) {
        if(uni(i.second.first, i.second.second)) ans += i.first;
    }

    for(ll i = 2; i <= n; ++i) if(uni(i, 1)) return -1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    iota(p, p + n + 1, 0);
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        e.push_back({c, {a, b}});
    }

    ll ans = mst();
    if(ans == -1) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
    return 0;
}