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
ll dp[1000007], n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    dp[0] = 1;
    for(ll i = 0; i <= 1000000; ++i) {
        for(ll j = 1; j <= 6; ++j) {
            if(i + j <= 1000000) {
                dp[i + j] = (dp[i + j] + dp[i])%MOD;
            }
        }
    }

    cout << dp[n] << '\n';
    return 0;
}