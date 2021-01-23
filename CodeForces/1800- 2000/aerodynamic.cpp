#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
ll n;
vector<pair<ll, ll>> v;

pair<ll, ll> p(pair<ll, ll> x, pair<ll, ll> y) {
    return {x.first - y.first, x.second - y.second};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    if(n%2 == 1) {
        cout << "NO\n";
        return 0;
    }

    for(ll i = 0; i < n/2; ++i) {
        ll j = i + n/2;
        if(p(v[(i + 1)%n], v[i]) != p(v[j], v[(j + 1)%n])) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}