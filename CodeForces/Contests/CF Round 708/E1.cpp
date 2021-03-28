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
ll t, n, k, a[200007];
bool comp[10000007];
vector<ll> p;
map<ll, bool> occ;

void sieve() {
    for(ll i = 2; i <= 10000000; ++i) {
        if(comp[i]) continue;
        p.push_back(i);
        for(ll j = i * 2; j <= 10000000; j += i) comp[j] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    sieve();
    while(t--) {
        occ.clear();
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        ll ans = 1;
        for(ll i = 0; i < n; ++i) {
            ll mask = 1;
            for(ll j = 0; j < sz(p) && p[j] * p[j] <= a[i]; ++j) {
                ll cnt = 0;
                while(a[i]%p[j] == 0) {
                    cnt++;
                    a[i] /= p[j];
                }

                if(cnt%2) mask *= p[j];
            }

            if(a[i] > 1) mask *= a[i];
            if(occ[mask]) {
                occ.clear();
                ans++;
            }

            occ[mask] = 1;
        }

        cout << ans << '\n';
    }

    return 0;
}