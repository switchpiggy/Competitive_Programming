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
ll p[500007], r[500007], n, m;
vector<ll> v;

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(x == y) return;
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    iota(p + 1, p + m + 1, 1);

    for(ll i = 1; i <= n; ++i) {
        ll k, a, b = m + 1;
        cin >> k >> a;
        if(k == 2) cin >> b;
        if(get(a) != get(b)) {
            uni(a, b);
            v.push_back(i);
        }
    }

    ll ans = 1;
    for(ll i = 0; i < sz(v); ++i) ans = (ans + ans)%MOD;

    cout << ans << ' ' << sz(v) << '\n';
    for(ll i : v) cout << i << ' ';
    cout << '\n';
}