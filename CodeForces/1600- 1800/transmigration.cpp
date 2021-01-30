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
#define flout cout << fixed << setprecision(12)
ll n, m;
long double k;
map<string, ll> pts;
vector<pair<string, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    ll kk = k * 100;
    for(ll i = 0; i < n; ++i) {
        string t;
        ll a;
        cin >> t >> a;
        pts[t] = a;
    }

    for(auto i = pts.begin(); i != pts.end(); ++i) {
        if(i->second * kk < 10000) {
            pts[i->first] = -1;
            continue;
        }
        v.push_back({i->first, kk * i->second});
    }

    for(ll i = 0; i < m; ++i) {
        string t;
        cin >> t;
        if(pts.find(t) == pts.end() || pts[t] == -1) {
            v.push_back({t, 0});
        }
    }

    cout << sz(v) << '\n';
    sort(all(v));
    for(pair<string, ll> i : v) cout << i.first << ' ' << (ll)floor((ld)i.second/100.0) << '\n';
    return 0;
}