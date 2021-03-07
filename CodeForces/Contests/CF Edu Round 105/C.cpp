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
ll t, n, m, a[200007], b[200007], px[200007], py[200007];
vector<ll> x, y, bx, by;
map<ll, ll> occ;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        x.clear();
        y.clear();
        bx.clear();
        by.clear();
        occ.clear();
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            occ[a[i]] = 1;
            if(a[i] < 0) x.push_back(-a[i]);
            else y.push_back(a[i]);
        }

        for(ll i = 0; i < m; ++i) {
            cin >> b[i];
            if(b[i] < 0) bx.push_back(-b[i]);
            else by.push_back(b[i]);
        }

        sort(all(x));
        sort(all(y));
        sort(all(bx));
        sort(all(by));

        for(ll i = 0; i < sz(by); ++i) {
            py[i] = (i ? py[i - 1] : 0) + occ[by[i]];
            // cout << py[i] << ' ';
        }

        for(ll i = 0; i < sz(bx); ++i) {
            px[i] = (i ? px[i - 1] : 0) + occ[-bx[i]];
        }

        ll cur = 0, ans1 = py[sz(by) - 1], ans2 = px[sz(bx) - 1];
        for(ll i = 0; i < sz(by); ++i) {
            while(cur < sz(y) && y[cur] <= by[i]) cur++;
            if(!cur) continue;
            ll l = lower_bound(all(by), by[i] - cur + 1) - by.begin();
            ans1 = max(ans1, i - l + 1 + py[sz(by) - 1] - py[i]);
        }

        cur = 0;
        for(ll i = 0; i < sz(bx); ++i) {
            while(cur < sz(x) && x[cur] <= bx[i]) cur++;
            if(!cur) continue;
            ll l = lower_bound(all(bx), bx[i] - cur + 1) - bx.begin();
            ans2 = max(ans2, i - l + 1 + px[sz(bx) - 1] - px[i]);
        }

        cout << ans1 + ans2 << '\n';
    }

    return 0;
}