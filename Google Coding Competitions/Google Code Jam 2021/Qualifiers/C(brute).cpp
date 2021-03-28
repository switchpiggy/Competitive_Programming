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
ll t, c, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(ll tc = 1; tc <= t; ++tc) {
        bool ok = 0;
        cout << "Case #" << tc << ": ";
        cin >> n >> c;
        vector<ll> v(n + 1);
        for(ll i = 1; i <= n; ++i) v[i] = i;

        do {
            ll ans = 0;
            vector<ll> a(v);
            for(ll i = 1; i < n; ++i) {

            ll cur = -1;
            for(ll j = 1; j <= n; ++j) {
                if(i == a[j]) {
                    cur = j;
                    break;
                }
            }

            if(i == cur) {
                ans++;
                continue;
            }

            ans += abs(cur - i) + 1;

            for(ll j = min(i, cur); j <= max(i, cur); ++j) {
                // cout << j << ' ' << max(cur, i) - (j - min(cur, i)) << '\n'; 
                if(j < max(cur, i) - (j - min(cur, i))) swap(a[j], a[max(cur, i) - (j - min(cur, i))]);
            }
            }   

            bool sorted = 1;
            for(ll i = 1; i <= n; ++i) {
                if(a[i] != i) {
                    sorted = 0;
                    break;
                }
            }

            if(!sorted) continue;

            if(ans == c) {
                ok = 1;
                for(ll i = 1; i <= n; ++i) cout << v[i] << ' ';
                cout << '\n';
                break;
            }
        } while(next_permutation(v.begin() + 1, v.end()));

        if(!ok) cout << "IMPOSSIBLE\n";
    }

    return 0;
}