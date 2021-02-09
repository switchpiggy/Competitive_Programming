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
ll t, x, y, n, a[100007], b[100007], c[100007];

bool comp(pair<ll, pair<ll, ll>> x, pair<ll, pair<ll, ll>> y) {
    if(x.first - x.second.first == y.first - y.second.first) return x.first < y.first;
    return x.first - x.second.first < y.first - y.second.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x >> y >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) cin >> b[i];

        bool ok = 0;

        ll sum = 0;
        for(ll i = 0; i < n; ++i) {
            c[i] = (b[i] + x - 1)/x * a[i];
            sum += c[i];
        }

        for(ll i = 0; i < n; ++i) {
            ll cur = y - (sum - c[i]);

            if(cur >= c[i] || (cur%a[i] != 0 && cur > c[i] - a[i])) {
                ok = 1;
                break;
            }
        }

        //cout << c[n - 1].first << ' ' << c[n - 1].second.first << ' ';

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}