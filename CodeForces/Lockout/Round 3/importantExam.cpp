#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[1007], ans;
vector<string> v;
map<char, ll> ma;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(ll i = 0; i < m; ++i) cin >> a[i];

    for(ll i = 0; i < m; ++i) {
        ma.clear();
        ll maxn = 0;
        for(ll j = 0; j < n; ++j) {
            ma[v[j][i]]++;
            maxn = max(maxn, ma[v[j][i]]);
        }

        ans += maxn * a[i];
    }

    cout << ans << '\n';
    return 0;
}