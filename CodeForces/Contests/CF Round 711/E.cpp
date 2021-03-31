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
ll n, k[507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> k[i];

    string res;
    auto ask = [&](ll x, ll y) {
        cout << "? " << x << ' ' << y << '\n';
        cout.flush();
        cin >> res;
        // cout.flush();
    };

    vector<pair<ll, ll>> v;
    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) v.push_back({i, j});
    }

    sort(all(v), [](pair<ll, ll> x, pair<ll, ll> y) {
        return abs(k[x.first] - k[x.second]) > abs(k[y.first] - k[y.second]);
    });

    for(auto i : v) {
        if(k[i.first] < k[i.second]) swap(i.first, i.second);
        ask(i.first + 1, i.second + 1);
        if(res == "Yes") {
            cout << "! " << i.first + 1 << ' ' << i.second + 1 << '\n';
            return 0;
        }
    }

    cout << "! 0 0\n";
    return 0;
}