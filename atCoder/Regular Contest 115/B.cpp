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
ll n, c[507][507], a[507], b[507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) cin >> c[i][j];
    }

    ll mins = INF;
    for(ll i = 0; i < n; ++i) mins = min(mins, c[i][0]);
    for(ll i = 0; i < n; ++i) a[i] = c[i][0] - mins;

    for(ll i = 0; i < n; ++i) b[i] = c[0][i] - a[0];

    bool ok = 1;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(a[i] + b[j] != c[i][j] || b[j] < 0 || a[i] < 0) {
                ok = 0;
                break;
            }
        }

        if(!ok) break;
    }

    cout << (ok ? "Yes\n" : "No\n");
    if(ok) {
        for(ll i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << '\n';
        for(ll i = 0; i < n; ++i) cout << b[i] << ' ';
        cout << '\n';
    }

    return 0;
}