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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    n = 1;
    for(ll i = 0; i < sz(s); ++i) n *= (s[i] - '0');

    ll ans = n, cur = 1;
    for(ll i = 0; i < sz(s); ++i) {
        if(s[i] > '0') ans = max(ans, cur * max(1, (s[i] - '0' - 1)) * (ll)pow(9, sz(s) - 1 - i));
        //else if(!i) 
        cur *= (s[i] - '0');
    }

    cout << ans << '\n';
    return 0;
}