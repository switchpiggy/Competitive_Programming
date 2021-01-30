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
ll t, n, c[100007], a[100007], b[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> c[i];
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) cin >> b[i];

        ll cur = abs(a[1] - b[1]), ans = 0;
        for(ll i = 1; i < n; ++i) {
            //cout << cur << ' ';
            ans = max(ans, cur + c[i] + 1);
            if(a[i + 1] == -1) continue;
            if(a[i + 1] == b[i + 1]) {
                cur = 0;
            } else {
                cur += 2 + abs(1 - min(a[i + 1], b[i + 1])) + abs(c[i] - max(a[i + 1], b[i + 1]));
            }
            cur = max(cur, abs(a[i + 1] - b[i + 1]));
        }

        cout << ans << '\n';
    }

    return 0;
}