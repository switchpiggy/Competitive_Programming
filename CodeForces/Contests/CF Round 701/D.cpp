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
ll n, m, a[507][507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> a[i][j];
    }

    for(ll i = 0; i < n; ++i, cout << '\n') {
        for(ll j = 0; j < m; ++j) {
            if(i%2 == j%2) {
                cout << 720720 << ' ';
                continue;
            }

            cout << 720720 + a[i][j] * a[i][j] * a[i][j] * a[i][j] << ' ';
        }
    }

    return 0;
}