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
ll t, n, a[107], d[107];

void solve(ll l, ll r, ll cur) {
    if(r < l) return;
    if(l == r) {
        d[l] = cur;
        return;
    }

    ll maxi = l;
    for(ll i = l; i <= r; ++i) {
        if(a[maxi] < a[i]) {
            maxi = i;
        }
    }

    d[maxi] = cur;
    solve(l, maxi - 1, cur + 1);
    solve(maxi + 1, r, cur + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> a[i];

        m0(d);
        solve(1, n, 0);

        for(ll i = 1; i <= n; ++i) cout << d[i] << ' ';
        cout << '\n';
    }

    return 0;
}