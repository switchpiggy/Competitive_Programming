#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y;
map<ll, ll> home;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> x >> y;
        home[x]++;
        v.push_back({x, y});
    }

    for(ll i = 0; i < n; ++i) {
        cout << (n - 1) + home[v[i].second] << ' ' << (n - 1) - home[v[i].second] << '\n';
    }

    return 0;
}