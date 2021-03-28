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
ll t, n, a[100007], nxt[100007], ans[100007];
bool vis[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> a[i], nxt[i] = i + 1;
        nxt[n] = 1;

        benq<ll> ben;
        for(ll i = 1; i <= n; ++i) if(__gcd(a[i], a[(i%n) + 1]) == 1) ben.push(i);

        m0(vis);
        // benq<ll> ben;
        ll cnt = 0;
        while(!ben.empty()) {
            ll f = ben.front();
            ben.pop();
            if(vis[f] || vis[nxt[f]]) continue;
            vis[nxt[f]] = 1;
            ans[cnt++] = nxt[f];
            nxt[f] = nxt[nxt[f]];
            if(__gcd(a[f], a[nxt[f]]) == 1) ben.push(f);
        }

        cout << cnt << ' ';
        for(ll i = 0; i < cnt; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}