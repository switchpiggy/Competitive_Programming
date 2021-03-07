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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<pair<ll, ll>> v;
    for(ll i = 0; i < 10; ++i) {
        for(ll j = 0; j < 10; ++j) {
            for(ll k = 0; k < 10; ++k) {
                v.insert({100 * i + j, 10000 * k + j});
            }
        }
    }

    cout << sz(v) << '\n';
    for(pair<ll, ll> i : v) cout << i.first << ' ' << i.second << '\n';
    return 0;
}