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
ll t, n, m, a[100007], b[100007], c[100007];
vector<ll> occ[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) occ[i].clear();
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) cin >> b[i];
        for(ll i = 0; i < m; ++i) {
            cin >> c[i];
            occ[c[i]].push_back(i);
        }

        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            if(b[i] == c[m - 1]) {
                ok = 1;
                break;
            }
        }

        if(!ok) {
            cout << "NO\n";
            continue;
        }

        //cout << "YES\n";
        vector<ll> v(m + 1);
        ll tt = 0, temp = occ[c[m - 1]].back();
        for(ll i = 0; i < n; ++i) {
            if(a[i] != b[i]) {
                if(occ[b[i]].empty()) {
                    ok = 0;
                    break;
                }

                if(b[i] == c[m - 1] && !tt) {
                    tt = i + 1;
                }

                v[occ[b[i]].back()] = i + 1;
                occ[b[i]].pop_back();
            }
        }

        if(!tt) {
            for(ll i = 0; i < n; ++i) {
                if(a[i] == b[i] && b[i] == c[m - 1]) {
                    tt = i + 1;
                    break;
                }
            }
        }

        if(!tt) {
            cout << "NO\n";
            continue;
        }

        for(ll i = 0; i < m; ++i) {
            if(v[i] == 0) {
                v[i] = tt;
            }
        }

        if(!ok) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(ll i = 0; i < m; ++i) cout << v[i] << ' ';
        cout << '\n';

        //cout << c[m - 1] << ' ' << tt << '\n';
    }

    return 0;
}