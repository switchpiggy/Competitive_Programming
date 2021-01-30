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
#define flout cout << fixed << setprecision(12)
ll t, n, k, p[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll sum = 0, ans = 0;
        for(ll i = 0; i < n; ++i) cin >> p[i];
        sum = p[0];
        for(ll i = 1; i < n; ++i) {
            //if(p[i] * 100 <= k * sum) continue;
            ans = max(ans, (p[i] * 100 + k - 1)/k - sum);
            //cout << (k * sum + 99)/100 << ' ';
            //p[i] += (k * sum + 99)/100;
            //cout << ans << ' ' << sum << '\n';
            sum += p[i];
        }

        cout << ans << '\n';
    }

    return 0;
}