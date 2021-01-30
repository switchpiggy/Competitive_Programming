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
ll t, n, d[307];

ll lcm(ll x, ll y) {
    return (x * y)/__gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            cin >> d[i];
        }

        sort(d, d + n);

        ll res = d[0] * d[n - 1];
        bool ok = 1;

        vector<ll> v;
        for(ll i = 2; i * i <= res; ++i) {
            if(res%i == 0) {
               v.push_back(i);
               if(res/i != i) v.push_back(res/i);
            }
        }

        sort(all(v));

        for(ll i = 0; i < min(n, sz(v)); ++i) {
            if(d[i] != v[i]) {
                ok = 0;
                break;
            }
        }

       if(sz(v) != n) ok = 0;
        cout << (ok ? res : -1) << '\n';
    }

    return 0;
}