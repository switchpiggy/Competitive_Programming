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
ll ans[11][11], d[11][11][11];
bool ok[11][11];

ll lcm(ll x, ll y) {
    return (x * y)/__gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    m1(ok);
    inf(d);

    for(ll x = 0; x < 10; ++x) {
        for(ll y = 0; y < 10; ++y) {
            for(ll i = 0; i < 10; ++i) {
                for(ll j = 0; j < 10; ++j) {
                    if(i || j)
                    d[x][y][(i * x + j * y)%10] = min(d[x][y][(i * x + j * y)%10], i + j);
                }
            }
        }
    }

    for(ll i = 1; i < sz(s); ++i) {
        //if(s[i] != '0') ok[0][0] = 0;
        ll k = ((s[i] - '0') - (s[i - 1] - '0') + 20)%10;

        for(ll i = 0; i < 10; ++i) {
            for(ll j = 0; j < 10; ++j) {
                if(d[i][j][k] == INF) {
                    ok[i][j] = 0;
                } else ans[i][j] += max(0ll, d[i][j][k] - 1);
            }
        }
    }

    for(ll i = 0; i < 10; ++i) {
        for(ll j = 0; j < 10; ++j) {
            if(!ok[i][j]) cout << "-1 ";
            else cout << ans[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}