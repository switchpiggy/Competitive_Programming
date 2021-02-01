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
#define INF 0x3f3f3f3f3f3f3f3f
#define flout cout << fixed << setprecision(12)
ll n, x, y;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    //sort(all(v));

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(i == j) continue;
            for(ll k = 0; k < n; ++k) {
                if(j == k || k == i) continue;
                ll y1 = v[j].second - v[i].second, y2 = v[k].second - v[j].second;
                ll x1 = v[j].first - v[i].first, x2 = v[k].first - v[j].first;
                if(y1 * x2 == x1 * y2) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}