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
ll t, n, m, occ[100007], ans[100007];
vector<ll> v[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        m0(occ);
        for(ll i = 0; i < m; ++i) v[i].clear();
        for(ll i = 0; i < m; ++i) {
            ll k;
            cin >> k;
            for(ll j = 0; j < k; ++j) {
                ll x;
                cin >> x;
                v[i].push_back(x);
            }

            ans[i] = v[i][0];
            occ[v[i][0]]++;
        }

        ll maxn = 1;
        for(ll i = 1; i <= n; ++i) if(occ[i] > occ[maxn]) maxn = i;

        for(ll i = 0; i < m && occ[maxn] > (m + 1)/2; ++i) {
            if(sz(v[i]) == 1) continue;
            if(ans[i] == maxn) {
                occ[maxn]--;
                ans[i] = v[i][1];
            }
        }

        if(occ[maxn] > (m + 1)/2) cout << "NO";
        else {
            cout << "YES\n";
            for(ll i = 0; i < m; ++i) cout << ans[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}