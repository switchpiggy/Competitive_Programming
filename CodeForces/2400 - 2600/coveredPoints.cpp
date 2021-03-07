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

struct seg {
    ll x1, y1, x2, y2;
    seg() {

    }
};

struct line {
    ll a, b, c;
    line() {
        
    }

    line(seg s) {
        b = s.x2 - s.x1;
        a = s.y1 - s.y2;
        c = -b * s.y1 - a * s.x1;
    }
};

ll delta(ll a, ll b, ll c, ll d) {
    return a * d - b * c;
}

ll calc(seg x) {
    ll dx = x.x1 - x.x2;
    ll dy = x.y1 - x.y2;
    return __gcd(abs(dy), abs(dx)) + 1;
}

bool in(ll x, ll l, ll r) {
    if(l > r) swap(l, r);
    return (l <= x && x <= r);
}

bool intersect(seg a, seg b, ll &x, ll &y) {
    line s(a);
    line t(b);

    ll p = delta(s.a, t.a, s.b, t.b), q = delta(s.c, t.c, s.b, t.b), r = delta(s.a, t.a, s.c, t.c);
    if(!p) return 0;
    if(abs(q)%abs(p) != 0 || abs(r)%abs(p) != 0) return 0;

    x = -q/p;
    y = -r/p;
    if(!in(x, a.x1, a.x2) || !in(x, b.x1, b.x2) || !in(y, a.y1, a.y2) || !in(y, b.y1, b.y2)) return 0;
    return 1;
}

ll n;
seg a[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll ans = 0;
    for(ll i = 0; i < n; ++i) cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    for(ll i = 0; i < n; ++i) {
        // cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        ans += calc(a[i]);

        ll x, y;
        set<pair<ll, ll>> st;
        for(ll j = 0; j < i; ++j) {
            if(intersect(a[j], a[i], x, y)) st.insert({x, y});
        }

        ans -= sz(st);
    }

    cout << ans << '\n';
    return 0;
}