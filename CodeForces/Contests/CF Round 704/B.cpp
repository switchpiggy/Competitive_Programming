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
ll t, n, p[100007], maxi[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> p[i];

        for(ll i = 1; i <= n; ++i) {
            if(p[maxi[i - 1]] < p[i]) maxi[i] = i;
            else maxi[i] = maxi[i - 1];
        }

        vector<ll> res;
        for(ll i = n; i >= 1; ) {
            for(ll j = maxi[i]; j <= i; ++j) res.push_back(p[j]);
            i = maxi[i] - 1;
        }

        for(ll i : res) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}