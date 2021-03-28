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
ll n, m, a, b, c, d[2507], p[2507];
vector<tuple<ll, ll, ll>> e;
vector<ll> ans;

bool neg_cycle() {
    inf(d);
    d[1] = 0;

    ll cur = -1;
    for(ll i = 0; i < n; ++i) {
        cur = -1;
        for(auto j : e) {
            ll x, y, z;
            tie(x, y, z) = j;
            if(d[y] > d[x] + z) {
                d[y] = d[x] + z;
                cur = y;
                p[y] = x;
            }
        }
    }

    if(cur == -1) return 0;

    for(ll i = 0; i < n; ++i) cur = p[cur];
    ll x = cur;
    while(sz(ans) <= 1 || x != cur) {
        ans.push_back(x);
        x = p[x];
    }

    ans.push_back(cur);

    reverse(all(ans));
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        e.push_back({a, b, c});
    }

    if(!neg_cycle()) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}