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
ll n;
ll x, y;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x >> y >> s;
    reverse(all(s));

    ll ans = 0;
    for(ll i = 0; i < x; ++i) {
        if(i < y && s[i] == '1') ans++;
        else if(i == y && s[i] == '0') ans++;
        else if(i > y && s[i] == '1') ans++;
    }

    cout << ans << '\n';
    return 0;
}