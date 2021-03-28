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
ll n, q, spt[200007][20], a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(ll i = 1; i <= n; ++i) cin >> spt[i][0];

    for(ll i = 1; i < 20; ++i) {
        for(ll j = 1; j + (1 << i) - 1 <= n; ++j) {
            spt[j][i] = min(spt[j][i - 1], spt[j + (1 << (i - 1))][i - 1]);
        }
    }

    while(q--) {
        cin >> a >> b;
        ll len = 1, cur = 0;
        while(len * 2 <= b - a + 1) len *= 2, cur++;

        cout << min(spt[a][cur], spt[b - len + 1][cur]) << '\n';
    }

    return 0;
}