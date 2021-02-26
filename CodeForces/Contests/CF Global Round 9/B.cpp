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
ll t, n, m, a[307][307], cnt[307][307];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        m0(a);
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= m; ++j) cin >> a[i][j];
        }

        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= m; ++j) {
               if((i == 1 && j == 1) || (i == n && j == 1) || (i == 1 && j == m) || (i == n && j == m)) cnt[i][j] = 2;
               else if(i == 1 || i == n || j == 1 || j == m) cnt[i][j] = 3;
               else cnt[i][j] = 4;
            }
        }
        bool ok = 1;
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= m; ++j) {
                if(a[i][j] > cnt[i][j]) {
                    ok = 0;
                    break;
                }

                a[i][j] = cnt[i][j];
            }

            if(!ok) break;
        }
        if(!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            for(ll i = 1; i <= n; ++i) {
                for(ll j = 1; j <= m; ++j) cout << a[i][j] << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}