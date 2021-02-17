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
ll n, x[107], dp[107][100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> x[i];

    dp[0][0] = 1;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j <= 100000; ++j) {
            dp[i + 1][j] += dp[i][j];
            if(j + x[i] <= 100000) dp[i + 1][j + x[i]] += dp[i][j];
        }
    }

    vector<ll> v;
    for(ll i = 1; i <= 100000; ++i) {
        //cout << dp[n][i] << ' ';
        if(dp[n][i]) v.push_back(i);
    }

    cout << sz(v) << '\n';
    for(ll i : v) cout << i << ' ';
    cout << '\n';
    return 0;
}