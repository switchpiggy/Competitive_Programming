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
ll t, n, m;
char a[507][507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= m; ++j) cin >> a[i][j];
        }

        if(m == 1) {
            for(ll i = 1; i <= n; ++i) cout << "X\n";
            continue;
        }

        for(ll i = 2; i <= m; i += 3) {
            for(ll j = 1; j <= n; ++j) a[j][i] = 'X';
            if(i + 2 > m) continue;
            bool ok = 0;
            for(ll j = 1; j <= n; ++j) {
                if(a[j][i + 1] == 'X' || a[j][i + 2] == 'X') {
                    a[j][i + 1] = a[j][i + 2] = 'X';
                    ok = 1;
                    break;
                }
            }

            if(!ok)  a[1][i + 1] = a[1][i + 2] = 'X';
        }

        if(m%3 == 1) {
            for(ll j = 1; j <= n; ++j) {
                if(a[j][m] == 'X') {
                    a[j][m - 1] = a[j][m] = 'X';
                }
            }
        }

        for(ll i = 1; i <= n; ++i, cout << '\n') {
            for(ll j = 1; j <= m; ++j) cout << a[i][j];
        }
    }

    return 0;
}