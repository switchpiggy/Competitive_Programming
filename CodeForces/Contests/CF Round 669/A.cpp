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
ll t, n, a[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll sum = 0;
        for(ll i = 0; i < n; ++i) cin >> a[i], sum += a[i];

        if(sum <= n/2) {
            cout << n - sum << '\n';
            for(ll i = 0; i < n - sum; ++i) cout << 0 << ' ';
        } else {
            cout << sum - sum%2 << '\n';
            for(ll i = 0; i < sum - sum%2; ++i) cout << 1 << ' ';
        }

        cout << '\n';
    }

    return 0;
}