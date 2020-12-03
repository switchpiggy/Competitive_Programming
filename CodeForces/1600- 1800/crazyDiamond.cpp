#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[300007], a[300007];
vector<pair<ll, ll>> v;

void s(ll x, ll y) {
    swap(a[x], a[y]);
    swap(p[a[x]], p[a[y]]);
    v.push_back({x, y});
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    } 

    for(ll i = 1; i <= n; ++i) {
        if(p[i] == i) continue;
        if(abs(p[i] - i) * 2 >= n) {
            s(p[i], i);
        } else if(i - 1 >= n/2) {
            s(i, 1);
            s(1, p[i]);
            s(i, 1);
        } else if(n/2 <= n - p[i]) {
            s(i, n);
            s(p[i], n);
            s(n, i);
        } else {
            s(i, n);
            s(1, n);
            s(p[i], 1);
            s(1, n);
            s(i, n);
        }

        //for(ll i = 1; i <=n; ++i) cout << a[i] << ' ';
        //cout << '\n';
    }

    //for(ll i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << (ll)v.size() << '\n';
    for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i].first << ' ' << v[i].second << '\n';
    return 0;
}