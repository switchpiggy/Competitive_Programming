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
ll t, n, m, a[200007];
vector<ll> x, y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        x.clear();
        y.clear();
        cin >> n >> m;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) {
            ll b;
            cin >> b;
            if(b == 2) y.push_back(a[i]);
            else x.push_back(a[i]);
        }

        sort(all(x), greater<ll>());
        sort(all(y), greater<ll>());
        x.insert(x.begin(), 0);
        y.insert(y.begin(), 0);

        for(ll i = 1; i < sz(x); ++i) x[i] += x[i - 1];
        for(ll i = 1; i < sz(y); ++i) y[i] += y[i - 1];

        ll j = sz(y) - 1, ans = LLONG_MAX;
        //if(y[j] >= m) ans = sz(y);
        for(ll i = 0; i < sz(x); ++i) {
            if(y[j] + x[i] < m) continue;
            while(j > 0 && y[j - 1] + x[i] >= m) j--;
            ans = min(ans, i + 2 * j);
            //cout << i << ' ' << j << ' ' << i + 2 * j + 2 << '\n';
        }        

        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }

    return 0;
}