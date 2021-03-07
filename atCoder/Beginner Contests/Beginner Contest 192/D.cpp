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
string s;
ll m;

bool check(ll b) {
    ll res = 0, cur = 1;
    for(ll i = 0; i < sz(s); ++i) {
        res += cur * (s[i] - '0');
        if(res > m) return 0;
        cur *= b;
    }

    return res <= m;
}

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll rec = fastpow(x, y/2);
    if(y%2) return (rec * rec * x);
    return (rec * rec);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> m;
    reverse(all(s));
    ll mins = 0, maxs = 0;
    for(ll i = 0; i < sz(s); ++i) mins = max(mins, (ll)(s[i] - '0'));

    ll l = mins + 1, r = maxs, ans = 0;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid;
    }

    cout << ans - mins << '\n';
    // cout << ans << '\n';
    // cout << mins << '\n';
    return 0;
}