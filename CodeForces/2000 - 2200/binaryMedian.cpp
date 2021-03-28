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
ll t, n, m;
map<ll, bool> occ;

ll nxtl(ll x) {
    ll ans = x - 1;
    while(occ[ans]) ans--;

    return ans;
}

ll nxtr(ll x) {
    ll ans = x + 1;
    while(occ[ans]) ans++;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        occ.clear();

        ll med = (1ll << (m - 1)) - 1, num = (1ll << m);
        // cout << med << ' ';
        for(ll i = 0; i < n; ++i) {
            string s;
            cin >> s;
            reverse(all(s));

            ll cur = 0;
            for(ll i = 0; i < m; ++i) {
                cur += (s[i] - '0') * (1ll << i);
            }

            occ[cur] = 1;
            if(cur == med) {
                if(num%2 == 1) med = nxtl(med);
                else med = nxtr(med);
            } else if(cur < med) {
                if(num%2 == 0) med = nxtr(med);
            } else {
                if(num%2 == 1) med = nxtl(med);
            }

            num--;
            // cout << med << ' ';
        }

        for(ll i = m - 1; i >= 0; --i) cout << ((med & (1ll << i)) ? 1 : 0);
        cout << '\n';
    }

    return 0;
}