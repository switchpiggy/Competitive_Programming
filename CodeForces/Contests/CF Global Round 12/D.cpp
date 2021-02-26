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
ll t, n, a[300007], spt[300007][19];
bool occ[300007];

ll range_min(ll y, ll x) {
    ll res = INF;
    for(ll i = 19; i >= 0; --i) {
        if(x - (1 << i) >= y) {
            x -= (1 << i);
            res = min(res, spt[x][i]);
        }
    }

    //cout << res << '\n';
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        m0(occ);
        for(ll i = 1; i <= n; ++i) cin >> a[i], spt[i][0] = a[i], occ[a[i]] = 1;
        for(ll i = 1; i < 19; ++i) {
            for(ll j = 1; j <= n - (1 << i) + 1; ++j) {
                spt[j][i] = min(spt[j][i - 1], spt[j + (1 << (i - 1))][i - 1]);
            }
        }

        ll l = 1, r = n, cur = n;
        for(ll i = 1; i <= n; ++i) {
            if(range_min(l, r + 1) != i) {
                cur = i;
                break;
            }

            if(a[l] != i && a[r] != i) {
                cur = i + 1;
                break;
            }

            if(a[l] == i) {
                l++;
            } else r--;
        }

        bool ok = 1;
        for(ll i = 1; i <= n; ++i) if(!occ[i]) {
            ok = 0;
            break;
        }

        cout << ok;
        for(ll i = 2; i <= n; ++i) cout << (i > n - cur + 1 ? 1 : 0);
        
        cout << '\n';
    }

    return 0;
}