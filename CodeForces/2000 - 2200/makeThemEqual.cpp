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
ll t, n, a[10007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        ll sum = 0;
        for(ll i = 0; i < n; ++i) {
            sum += a[i];
        }

        if(sum%n) {
            cout << "-1\n";
            continue;
        }

        vector<pair<pair<ll, ll>, ll>> v;
        for(ll i = 1; i < n; ++i) {
            if(a[i]%(i + 1)) {
                v.push_back({{0, i}, (i + 1) - a[i]%(i + 1)});
                a[i] += (i + 1) - a[i]%(i + 1);
            }

            v.push_back({{i, 0}, a[i]/(i + 1)});
        }

        for(ll i = 1; i < n; ++i) {
            v.push_back({{0, i}, sum/n});
        }

        cout << sz(v) << '\n';
        for(pair<pair<ll, ll>, ll> i : v) {
            cout << i.first.first + 1 << ' ' << i.first.second + 1 << ' ' << i.second << '\n';
        }
    }

    return 0;
}