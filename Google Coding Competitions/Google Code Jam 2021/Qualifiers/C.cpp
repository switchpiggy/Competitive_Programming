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
ll t, c, n;

vector<ll> solve(ll x, ll k) {
    if(x == 1) {
        if(k != 1) return {};
        return {1};
    }

    vector<ll> res(x);
    ll cur = -1;
    for(ll i = 1; i <= x; ++i) {
        if(x - 1 <= k - i && k - i <= (x * (x - 1))/2) cur = max(cur, i);
    }

    if(cur == -1) return {};

    vector<ll> rec = solve(x - 1, k - cur);
    if(!sz(rec)) return {};

    ll cnt = 0;
    for(ll i = 1; i < x; ++i) {
        res[i] = rec[i - 1] + 1;
    }

    res[0] = 1;

    for(ll i = 0; i < cur/2; ++i) {
        swap(res[i], res[cur - i - 1]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(ll tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        cin >> n >> c;
        vector<ll> ans = solve(n, c + 1);

        if(!sz(ans)) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for(ll i : ans) cout << i << ' ';
        cout << '\n';
    }
}