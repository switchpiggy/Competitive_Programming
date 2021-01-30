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
vector<ll> ans[107];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(ll i = 1; i <= n; ++i) {
        ans[i].push_back(i);
    }

    ll cur = n + 1;

    for(pair<ll, ll> i : v) {
        ans[i.first].push_back(cur);
        ans[i.second].push_back(cur);
        cur++;
    }

    for(ll i = 1; i <= n; ++i) {
        cout << sz(ans[i]) << '\n';
        for(ll j : ans[i]) cout << i << ' ' << j << '\n';
    }

    return 0;
}