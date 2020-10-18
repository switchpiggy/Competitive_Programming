#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
pair<ll, ll> a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    vector<ll> v, u;
    ll sumU = 0, sumV = 0;

    for(ll i = 0; i + 1 < n; i += 2) {
        if(sumU >= sumV) {
            sumU += a[i].first;
            sumV += a[i + 1].first;
            v.push_back(a[i + 1].second);
            u.push_back(a[i].second);
        } else {
            sumV += a[i].first;
            sumU += a[i + 1].first;
            v.push_back(a[i].second);
            u.push_back(a[i + 1].second);
        }
    }

    if(n%2 == 1) {
        if(sumU >= sumV) v.push_back(a[n - 1].second);
        else u.push_back(a[n - 1].second);
    }

    cout << (ll)v.size() << '\n';
    for(auto i : v) cout << i + 1 << ' ';
    cout << '\n';
    cout << (ll)u.size() << '\n';
    for(auto i : u) cout << i + 1 << ' ';
    cout << '\n';

    return 0;
}