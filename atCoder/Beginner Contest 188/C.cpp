
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < 1ll << n; ++i) {
        ll x;
        cin >> x;
        a.push_back({x, i + 1});
    }

    //sort(a.begin(), a.end());

    vector<pair<ll, ll>> b;
    while((ll)a.size() > 2) {
        b.clear();
        for(ll i = 0; i < (ll)a.size() - 1; i += 2) {
            //cout << a[i + 1] << ' ';
            if(a[i + 1].first >= a[i].first) b.push_back({a[i + 1].first, a[i + 1].second});
            else b.push_back({a[i].first, a[i].second});
        }

        a = b;
    }

    if(a[0].first < a[1].first) cout << a[0].second << '\n';
    else cout << a[1].second << '\n';
    return 0;
}