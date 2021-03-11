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
ll t, n, k, a[100007];
map<ll, bool> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cnt.clear();
        cin >> n >> k;
        ll maxn = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i]] = 1;
            maxn = max(maxn, a[i]);
        }

        bool ok = 1;
        ll mex = n;
        for(ll i = 0; i < n; ++i) {
            if(!cnt[i]) {
                mex = i;
                ok = 0;
                break;
            }
        }

        // cout << mex << ' ' << maxn << '\n';
        if(ok) cout << n + k << '\n';
        else cout << n + (k ? !cnt[(mex + maxn + 1)/2] : 0) << '\n';
    }

    return 0;
}