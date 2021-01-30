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
ll n, p[307][307], q[307];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            ll a;
            cin >> a;
            p[i][a] = j;
        }
    }

    for(ll i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        q[a] = i;
    }

    for(ll i = 1; i <= n; ++i) {
        ll maxCard = -1, ans = -1, res = -1;
        for(ll j = 1; j <= n; ++j) {
            if(j == i) continue;
            if(maxCard == -1 || q[maxCard] > q[j]) maxCard = j;
            if(ans == -1 || p[i][ans] > p[i][maxCard]) {
                ans = maxCard;
                res = j;
            }
        }

        cout << ans << ' ';
    }

    cout << '\n';
    return 0;
}