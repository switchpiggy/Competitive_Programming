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
ll t, n, a[200007], m;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        cin >> m;
        for(ll i = 0; i < m; ++i) {
            ll x, y;
            cin >> x >> y;
            v.push_back({x, y});
        } 
        
        sort(all(v));
        for(ll i = sz(v) - 2; i >= 0; --i) v[i].second = max(v[i].second, v[i + 1].second);

        ll i = 0, ans = 0;
        while(i < n) {
            ll cur = 0, maxn = 0;
            while(i + cur < n) {
                maxn = max(maxn, a[i + cur]);
                ll k = lower_bound(all(v), make_pair(maxn, -1ll)) - v.begin();
                if(k == m || v[k].second < cur + 1) break;
                cur++;
            }
            
            if(!cur) {
                ans = -1;
                break;
            }
            
            ans++;
            i += cur;
            //cout << cur << ' ';
        }

        cout << ans << '\n';
    }

    return 0;
}