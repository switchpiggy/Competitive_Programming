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
ll n, p[20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll tot = 0;
    for(ll i = 0; i < n; ++i) cin >> p[i], tot += p[i];

    ll ans = LLONG_MAX;
    for(ll i = 0; i < (1 << n); ++i) {
        ll sum = 0;
        for(ll j = 0; j < n; ++j) {
            if((i & (1 << j))) sum += p[j];
        }

        ans = min(ans, abs(sum - (tot - sum)));
    }

    cout << ans << '\n';
}