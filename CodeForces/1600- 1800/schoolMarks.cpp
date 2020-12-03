#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, p, x, y;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> p >> x >> y;
    for(ll i = 0; i < k; ++i) {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    ll cnt = 0;
    for(ll i = 0; i < k; ++i) cnt += (v[i] < y);
    if(cnt > (n - 1)/2) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < n - k; ++i) {
        if(cnt < (n - 1)/2) {
            v.push_back(1);
            cnt++;
        } else {
            v.push_back(y);
        }
    }

    ll sum = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) sum += v[i];

    if(sum > x) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = k; i < (ll)v.size(); ++i) {
        cout << v[i] << ' ';
    }

    return 0;
}