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
ll t, n, ans;
vector<ll> v;
vector<pair<ll, ll>> ops;

void op(ll x, ll y) {
    swap(v[x], v[y]);
    ops.push_back({x, y});
    ans += (x - y) * (x - y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        v.clear();
        ops.clear();
        v.resize(n + 1);
        iota(all(v), 0);
        ans = 0;

        op(1, n);
        for(ll i = 2; i <= n/2; ++i) {
            op(n - i + 1, 1);
            op(i, n);
        }

        if(n%2) op((n + 1)/2, 1);

        reverse(all(ops));
        cout << ans << '\n';
        for(ll i = 1; i <= n; ++i) cout << v[i] << ' ';
        cout << '\n' << sz(ops) << '\n';
        for(pair<ll, ll> p : ops) cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}