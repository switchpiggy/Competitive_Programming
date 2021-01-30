#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll n, l, r, a[100007], p[100007], order[100007], res[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> r;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 1; i <= n; ++i) cin >> p[i];
    for(ll i = 1; i <= n; ++i) {
        order[p[i]] = a[i];
    }

    res[0] = LLONG_MIN;
    for(ll i = 1; i <= n; ++i) {
        ll cur = res[i - 1] + 1;
        cur = min(cur, r - order[i]);
        cur = max(cur, l - order[i]);

        //last = cur;
        res[i] = cur;
    }

    for(ll i = 2; i <= n; ++i) {
        if(res[i] <= res[i - 1]) {
            cout << "-1\n";
            return 0;
        }
    }

    for(ll i = 1; i <= n; ++i) cout << order[p[i]] + res[p[i]] << ' ';
}