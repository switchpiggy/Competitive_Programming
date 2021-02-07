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
ll n;
vector<pair<ll, ll>> f, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        char c;
        ll x, y;
        cin >> c >> x >> y;
        if(c == 'F') f.push_back({x, y});
        else m.push_back({x, y});
    }

    ll ans = 0;
    for(ll i = 1; i <= 366; ++i) {
        ll a = 0, b = 0;
        for(pair<ll, ll> j : f) {
            if(j.first <= i && i <= j.second) a++;
        }

        for(pair<ll, ll> j : m) {
            if(j.first <= i && i <= j.second) b++;
        }

        //if(i == 117) cout << a << ' ' << b << '\n';

        ans = max(ans, min(a, b) * 2);
    }

    cout << ans << '\n';
}