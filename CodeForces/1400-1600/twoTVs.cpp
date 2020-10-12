#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> v;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b + 1, -1});
    }

    sort(v.begin(), v.end());

    ll cur = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        cur += v[i].second;
        if(cur > 2) {
            cout << "NO\n";
            return 0;
        }
    } 

    cout << "YES\n";
    return 0;
}