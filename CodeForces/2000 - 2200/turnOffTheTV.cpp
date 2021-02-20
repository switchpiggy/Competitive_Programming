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
ll n, a[200007];
vector<pair<pair<ll, ll>, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        ll x, y;
        cin >> x >> y;
        v.push_back({{x, y}, i});
    }

    sort(all(v), [](pair<pair<ll, ll>, ll> x, pair<pair<ll, ll>, ll> y) {
        if(x.first.first == y.first.first) {
            if(x.first.second == y.first.second) return x.second < y.second;
            return x.first.second > y.first.second;
        }
        return x.first.first < y.first.first;
    });

    ll maxn = -1;
    for(ll i = 0; i < n; ++i) {
        if(v[i].first.second <= maxn) {
            cout << v[i].second << '\n';
            return 0;
        }

        a[i] = maxn;
        maxn = max(maxn, v[i].first.second);
    }

    for(ll i = 1; i < n - 1; ++i) {
        ll k = upper_bound(all(v), make_pair(make_pair(a[i] + 1, LLONG_MAX), LLONG_MAX)) - v.begin();
        //cout << k << "\n";
        k--;
        if(k == i) k--;
        if(k < 0) continue;
        if(a[k] >= v[i].first.second) {
            //cout << a[k] << "\n" << k << '\n';
            cout << v[i].second << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}