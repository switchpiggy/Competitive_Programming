#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    ll prev = -1;
    for(ll i = n - 1; i >= 0; --i) {
        if(max(v[i].first, v[i].second) < prev) {
            cout << "NO\n";
            return 0;
        }

        if(min(v[i].first, v[i].second) >= prev) {
            prev = min(v[i].first, v[i].second);
        } else prev = max(v[i].first, v[i].second);
    }

    cout << "YES\n";
    return 0;
}