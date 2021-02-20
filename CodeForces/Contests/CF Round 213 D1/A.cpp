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
ll a;
string s;
map<ll, ll> ok;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> s;
    ll ans = 0;
    for(ll i = 0; i < sz(s); ++i) {
        ll cur = 0;
        for(ll j = i; j < sz(s); ++j) {
            cur += (s[j] - '0');
            ok[cur]++;
        }
    }

    if(!a) {
        ll sum = ok[0] * ok[0];
        for(auto i = ok.begin(); i != ok.end(); ++i) {
            if(i->first == 0) continue;
            sum += 2 * ok[0] * i->second;
        }

        cout << sum << '\n';
        return 0;
    }
    
    for(ll i = 1; i * i <= a; ++i) {
        if(a%i == 0) {
            if(i * i == a) ans += ok[i] * ok[i];
            else ans += 2 * ok[i] * ok[a/i];
        }
    }
    
    cout << ans << '\n';
    return 0;
}