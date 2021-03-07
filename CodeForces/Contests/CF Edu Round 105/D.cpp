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
ll n, a[507][507], ans[507], cnt;
vector<pair<ll, ll>> e;

ll dfs(vector<ll> x) {
    if(sz(x) == 1) return x[0];

    vector<vector<ll>> res;
    ll cur = ++cnt;

    ll maxn = 0;
    for(ll i : x) maxn = max(maxn, a[x[0]][i]);

    while(sz(x)) {
        vector<ll> take, left;
        take.push_back(x[0]);
        for(ll i = 1; i < sz(x); ++i) {
            if(a[x[0]][x[i]] == maxn) {
                left.push_back(x[i]);
            } else take.push_back(x[i]);
        }

        res.push_back(take);
        x = left;
    }

    ans[cur] = maxn;
    for(vector<ll> i : res) {
        e.push_back({dfs(i), cur});
    }

    return cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<ll> v;
    for(ll i = 1; i <= n; ++i) {
        v.push_back(i);
        for(ll j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if(i == j) ans[i] = a[i][j];
        }
    }

    cnt = n;
    ll res = dfs(v);

    cout << cnt << '\n';
    for(ll i = 1; i <= cnt; ++i) cout << ans[i] << ' ';
    cout << '\n';
    // assert(sz(e) == cnt - 1);
    cout << res << '\n';
    for(pair<ll, ll> p : e) cout << p.first << ' ' << p.second << '\n';
    return 0;
}