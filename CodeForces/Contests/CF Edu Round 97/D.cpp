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
ll t, n, a[200007], p[200007];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> p[i];
        vector<ll> g;

        ll cur = 1;
        for(ll i = 3; i <= n; ++i) {
            //cout << p[i] << ' ';
            if(p[i] < p[i - 1] + 1) {
                g.push_back(cur);
                cur = 1;
            } else cur++;
        }

        g.push_back(cur);

        ll prev = 1;
        cur = 0;
        ll ans = 1;
        for(ll i = 0; i < sz(g); ++i) {
            if(!prev) {
                prev = cur;
                cur = 0;
                ans++;
            }

            prev--;
            cur += g[i];
        }

        cout << ans << '\n';
    }

    return 0;
}