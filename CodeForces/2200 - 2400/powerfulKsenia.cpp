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
ll n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll x = 0;
    for(ll i = 0; i < n; ++i) cin >> a[i], x ^= a[i];

    if(n%2 == 0 && x) {
        cout << "NO\n";
        return 0;
    }

    if(n%2 == 0) n--;

    cout << "YES\n";
    vector<tuple<ll, ll, ll>> ans;

    for(ll i = n; i > 1; i -= 2) {
        ans.push_back({i, i - 1, i - 2});
    }

    for(ll i = n; i > 1; i -= 2) {
        ans.push_back({i, i - 1, 1});
    }

    cout << sz(ans) << '\n';
    for(auto i : ans) {
        ll x, y, z;
        tie(x, y, z) = i;
        cout << x << ' ' << y << ' ' << z << '\n';
    }

    return 0;
}