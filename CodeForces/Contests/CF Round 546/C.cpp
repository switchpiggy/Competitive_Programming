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
vector<ll> a[1007], b[1007];
ll n, m;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            a[i + j].push_back(x);
        }
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            b[i + j].push_back(x);
        }
    }

    bool ok = 1;
    for(ll i = 0; i <= n + m - 2; ++i) {
        sort(all(a[i]));
        sort(all(b[i]));

        for(ll j = 0; j < sz(a[i]); ++j) {
            if(a[i][j] != b[i][j]) {
                ok = 0;
                break;
            }
        }

        if(!ok) break;
    }

    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}