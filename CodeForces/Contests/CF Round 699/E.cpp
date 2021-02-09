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
ll n, a[500007], l[500007], r[500007], cnt[500007], occ[500007], dp[500007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    for(ll i = 1; i <= n; ++i) {
        if(!l[a[i]]) l[a[i]] = i;
        r[a[i]] = i;
        cnt[a[i]]++;
    }

    for(ll i = n; i >= 1; --i) {
        occ[a[i]]++;
        if(i == l[a[i]]) {
            dp[i] = max(dp[i], cnt[a[i]] + dp[r[a[i]] + 1]);
        } else dp[i] = max(dp[i], occ[a[i]]);

        dp[i] = max(dp[i], dp[i + 1]);
    }

    cout << n - dp[1] << '\n';
}