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
ll t, n, c[200007];
map<ll, bool> used;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        used.clear();
        cin >> n;
        vector<ll> p, d;

        for(ll i = 1; i * i <= n; ++i) {
            if(n%i == 0) {
                if(n/i != i) d.push_back(n/i);
                if(i > 1) d.push_back(i);
            }
        }

        sort(all(d));
        if(sz(d) == 3 && d[2] == d[1] * d[0] && __gcd(d[1], d[0]) == 1) {
            cout << d[0] << ' ' << d[1] << ' ' << d[2] << '\n' << 1 << '\n';
            continue;
        }

        for(ll i = 2; i * i <= n; ++i) {
            if(n%i == 0) {
                p.push_back(i);
                while(n%i == 0) n /= i;
            }
        }

        if(n > 1) p.push_back(n);

        sort(all(p));

        for(ll i = 0; i < sz(p); ++i) {
            ll cur = p[i], nxt = p[(i + 1)%sz(p)];

            for(ll j = 0; j < sz(d); ++j) {
                if(d[j]%cur == 0 && d[j]%nxt == 0 && !used[d[j]]) {
                    used[d[j]] = 1;
                    c[i] = d[j];
                    break;
                }
            }
        }

        for(ll i = 0; i < sz(p); ++i) {
            cout << p[i] << ' ';
            used[p[i]] = 1;
            for(ll j = 0; j < sz(d); ++j) {
                if(!used[d[j]] && d[j]%p[i] == 0) {
                    cout << d[j] << ' ';
                    used[d[j]] = 1;
                }
            }

            if(sz(p) > 1) cout << c[i] << ' ';
        }

        cout << "\n0\n";
    }

    return 0;
}