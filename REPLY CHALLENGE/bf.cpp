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

void fileIO() {
    freopen("tt.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
}

ll t, n, k, a[100007], ans[100007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO();
    cin >> t;
    for(ll tc = 1; tc <= t; ++tc) {
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) cin >> a[i], ans[i][0] = i;

        for(ll i = 0; i < k; ++i) {
            for(ll j = 0; j < n; ++j) {
                ans[a[j]][1] = ans[j][0];
            }

            for(ll j = 0; j < n; ++j) {
                ans[j][0] = ans[j][1];
                ans[j][1] = 0;
            }
        }

        cout << "Case #" << tc << ": ";
        for(ll i = 0; i < n; ++i) cout << ans[i][0] << ' ';
        cout << '\n';
    }

    return 0;
}