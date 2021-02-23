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
ll t, n, r[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input-xray-833e.in", "r", stdin);
    //freopen("B.out", "w", stdout);
    cin >> t;

    for(ll tc = 1; tc <= t; ++tc) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> r[i];
        ll ans = 0;

        for(ll i = 1; i <= 1000; ++i) {
            for(ll j = 0; j < n; ++j) {
                if((!j || r[j - 1] < i) && r[j] >= i) ans++;
            }
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}