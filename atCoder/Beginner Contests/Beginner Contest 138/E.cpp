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
string s, t;
vector<ll> occ[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    for(ll i = 0; i < sz(s); ++i) {
        occ[s[i] - 'a'].push_back(i);
    }

    ll ans = 0;
    for(ll i = 0; i < sz(t); ++i) {
        ll res = -1;
        for(ll j : occ[t[i] - 'a']) {
            if(j >= ans%sz(s)) {
                res = j;
                break;
            }
        }

        if(res != -1) {
            ans += (res - ans%sz(s) + 1);
        } else {
            if(occ[t[i] - 'a'].empty()) {
                cout << "-1\n";
                return 0;
            }

            ans += (sz(s) - ans%sz(s));
            ans += occ[t[i] - 'a'][0] + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}