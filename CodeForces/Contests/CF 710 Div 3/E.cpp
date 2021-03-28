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
ll t, n, q[200007], ans[200007], ans2[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        m0(ans);
        m0(ans2);
        cin >> n;
        set<ll> s;
        for(ll i = 1; i <= n; ++i) cin >> q[i], s.insert(i);

        for(ll i = 1; i <= n; ++i) {
            if(q[i] > q[i - 1]) {
                s.erase(q[i]);
                ans[i] = ans2[i] = q[i];
            }
        }

        set<ll> st(s);
        for(ll i = 1; i <= n; ++i) {
            if(!ans[i]) {
                ans[i] = *s.begin();
                s.erase(*s.begin());
            }
        }

        for(ll i = 1; i <= n; ++i) {
            if(!ans2[i]) {
                auto itr = st.lower_bound(q[i]);
                ll cur = *prev(itr);
                // cout << cur << ' ';
                ans2[i] = cur;
                st.erase(cur);
            }
        }
        // cout << '\n';

        for(ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << '\n';
        for(ll i = 1; i <= n; ++i) cout << ans2[i] << ' ';
        cout << '\n';
    }

    return 0;
}