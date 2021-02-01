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
#define flout cout << fixed << setprecision(12)
ll t, n, l[200007], r[200007];
vector<ll> a, c;

bool solve(vector<ll> &x) {
    ll cur = 0;
    for(ll i = 0; i < sz(x); ++i) {
        cur = x[i] - cur;
        if(cur < 0) return 0;
        if(x[i] < 0) return 0;
    }

    return cur == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        a.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            a.push_back(x);
        }

        if(solve(a)) {
            cout << "YES\n";
            continue;
        }

        l[0] = a[0];
        for(ll i = 1; i < n; ++i) {
            l[i] = a[i] - l[i - 1];
            if(l[i] < 0 || (i && l[i - 1] == -1)) {
                l[i] = -1;
            }
        }

        r[n] = 0;
        for(ll i = n - 1; i >= 0; --i) {
            r[i] = a[i] - r[i + 1];
            if(r[i] < 0 || r[i + 1] == -1) {
                r[i] = -1;
            }
        }

        bool ok = 0;
        for(ll i = 0; i < n - 1; ++i) {
            c.clear();
            c.push_back((i ? l[i - 1] : 0));
            c.push_back(a[i + 1]);
            c.push_back(a[i]);
            c.push_back(r[i + 2]);

            if((c[0] != -1 && c[3] != -1) && solve(c)) {
                ok = 1;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}