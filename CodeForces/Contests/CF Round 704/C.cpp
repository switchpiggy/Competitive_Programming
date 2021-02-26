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
ll n, m, pref[200007], suf[200007];
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    ll cur = 0;
    for(ll i = 0; i < sz(s); ++i) {
        if(t[cur] == s[i]) {
            pref[cur++] = i + 1;
        }
    }

    cur = sz(t) - 1;
    for(ll i = sz(s) - 1; i >= 0; --i) {
        if(t[cur] == s[i]) {
            suf[cur--] = i + 1;
        }
    }


    ll ans = LLONG_MIN;
    for(ll i = 0; i < sz(t) - 1; ++i) {
        ans = max(ans, suf[i + 1] - pref[i]);
    }

    cout << ans << '\n';
    return 0;
}