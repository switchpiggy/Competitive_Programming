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
ll n, x[1000007];
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> t;
    ll a = 0, b = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == '0') a++;
        if(t[i] == '0') b++;
    }

    if(a^b) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        if(s[i] == t[i]) continue;
        if(s[i] == '1') x[i] = 1;
        else x[i] = -1;
    }

    ll cur = 0, cur2 = 0, maxn = 0, minn = 0;
    for(ll i = 0; i < n; ++i) {
        cur += x[i];
        cur2 += x[i];
        if(cur < 0) cur = 0;
        if(cur2 > 0) cur2 = 0;
        maxn = max(maxn, cur);
        minn = min(minn, cur2);
    }

    cout << max(abs(maxn), abs(minn)) << '\n';
    return 0;
}