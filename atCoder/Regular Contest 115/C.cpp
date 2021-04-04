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
ll n, dp[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[1] = 1;
    for(ll i = 2; i <= n; ++i) {
        for(ll j = 2; j * j <= n; ++j) {
            if(i%j == 0) {
                dp[i] = dp[i/j] + 1;
                break;
            }   
        }

        if(!dp[i]) dp[i] = 2;
    }

    for(ll i = 1; i <= n; ++i) cout << dp[i] << ' ';
    cout << '\n';
}
