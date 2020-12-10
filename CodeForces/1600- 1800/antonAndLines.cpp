#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x1, x2;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x1 >> x2;
    for(ll i = 0; i < n; ++i) {
        ll k, b;
        cin >> k >> b;
        v.push_back({x1 * k + b, x2 * k + b});
    }

    sort(v.begin(), v.end());
    ll y = v[0].second;
    for(ll i = 1; i < n; ++i) {
        if(v[i].second < y) {
            cout << "YES\n";
            return 0;
        }

        y = v[i].second;
    }

    cout << "NO\n";
    return 0;
}