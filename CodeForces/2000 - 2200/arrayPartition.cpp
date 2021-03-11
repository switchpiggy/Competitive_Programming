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

ll t, n, a[200007];
multiset<ll> l, m, r;

void move(multiset<ll> &from, multiset<ll> &to, ll x) {
    from.erase(from.find(x));
    to.insert(x);
}

bool check() {
    if(!sz(l) || !sz(r) || !sz(m)) return 0;
    if(*l.rbegin() == *r.rbegin() && *r.rbegin() == *m.begin()) {
        cout << "YES\n" << sz(l) << ' ' << sz(m) << ' ' << sz(r) << '\n';
        return 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        // st.init(n);
        for(ll i = 0; i < n; ++i) cin >> a[i];
        l.clear();
        m.clear();
        r.clear();
        
        for(ll i = 0; i < n; ++i) m.insert(a[i]);
        ll cur = n - 1;
        bool ok = 0;

        for(ll i = 0; i < n - 2; ++i) {
            move(m, l, a[i]);
            ll maxn = *l.rbegin();
            while(cur >= i + 1 && a[cur] <= maxn) {
                move(m, r, a[cur]);
                cur--;
            }

            while(cur < i + 1) {
                move(r, m, a[cur + 1]);
                cur++;
            }

            move(l, m, a[i]);
            if(check()) {
                ok = 1;
                break;
            }
            move(m, l, a[i]);

            if(sz(r)) {
                move(r, m, a[cur + 1]);
                if(check()) {
                    ok = 1;
                    break;
                }
                move(m, r, a[cur + 1]);
            }

            if(check()) {
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "NO\n";
    }

    return 0;
}