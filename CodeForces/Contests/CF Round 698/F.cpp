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
vector<pair<ll, ll>> v;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    ll cur = 0, cnt = 1;
    vector<ll> ans = {0};

    while(cnt < n) {
        ll nxt = -1;
        for(ll i = 0; i < n; ++i) {
            if(i == cur || v[i].first == LLONG_MAX || v[i].second == LLONG_MAX) continue;
            if(nxt == -1) {
                nxt = i;
                continue;
            }

            ll a = abs(v[i].first - v[cur].first), b = abs(v[i].second - v[cur].second);
            ll c = abs(v[cur].first - v[nxt].first), d = abs(v[cur].second - v[nxt].second);
            //cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
            if((a + c) * (a - c) > (d - b) * (d + b)) {
                nxt = i;
            }
        }

        if(nxt == -1) {
            cout << "-1\n";
            return 0;
        }

        ans.push_back(nxt);
        v[cur].first = v[cur].second = LLONG_MAX;
        cur = nxt;
        cnt++;
    }

    for(ll i : ans) cout << i + 1 << ' ';
    return 0;
}