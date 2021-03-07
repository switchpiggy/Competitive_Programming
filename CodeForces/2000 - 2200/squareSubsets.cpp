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
ll n, a[100007], cnt[71], dp[2][(1 << 20)], pow2[100007];
vector<ll> p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    pow2[0] = 1;
    for(ll i = 1; i <= n; ++i) pow2[i] = (pow2[i - 1] * 2)%MOD;

    for(ll i = 2; i <= 70; ++i) {
        bool ok = 1;
        for(ll j = 2; j * j <= i; ++j) {
            if(i%j == 0) {
                ok = 0;
                break;
            }
        }

        if(ok) p.push_back(i);
    }

    

    dp[0][0] = 1;
    for(ll i = 0; i < 70; ++i) {
        ll mask = 0;
        for(ll j = 0; j < sz(p); ++j) {
            ll cnt = 0, cur = i + 1;
            while(cur%p[j] == 0) {
                cnt++;
                cur /= p[j];
            }

            if(cnt%2) mask |= (1 << j);
        }

        for(ll j = 0; j < (1 << sz(p)); ++j) {
            if(cnt[i + 1]) (dp[1][j^mask] += (dp[0][j] * pow2[cnt[i + 1] - 1])%MOD) %= MOD;
            (dp[1][j] += dp[0][j] * (cnt[i + 1] ? pow2[cnt[i + 1] - 1] : 1)) %= MOD;
        }

        for(ll j = 0; j < (1 << sz(p)); ++j) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }

    cout << dp[0][0] - 1 << '\n';
    return 0;
}