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
ll n, a, b, res[100007];
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.second == y.second) return x.first < y.first;
    return x.second < y.second;
}

bool cmp2(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.second == y.second) return x.first > y.first;
    return x.second < y.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    for(ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        v.push_back({i, x});
    } 

    if(a == b) {
        for(ll i = 0; i < n; ++i) {
            if(i < n/2) cout << 1 << ' ';
            else cout << 2 << ' ';
        }

        cout << '\n';
        return 0;
    } else if(a > b) {
        sort(all(v), cmp);
        for(ll i = 0; i < a; ++i) res[v[i].first] = 1;
        for(ll i = a; i < n; ++i) res[v[i].first] = 2;
    } else {
        sort(all(v), cmp2);
        for(ll i = 0; i < b; ++i) res[v[i].first] = 2;
        for(ll i = b; i < n; ++i) res[v[i].first] = 1;
    }
    
    for(ll i = 0; i < n; ++i) cout << res[i] << ' ';
    cout << '\n';
    return 0;
}