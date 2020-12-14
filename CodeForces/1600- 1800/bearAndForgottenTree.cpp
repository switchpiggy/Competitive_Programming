#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, d, h;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> h;
    ll cur = 2;

    if(n == 2) {
        cout << "1 2\n";
        return 0;
    }

    if(d > 2 * h || d == 1) {
        cout << "-1\n";
        return 0;
    }

    ll prev = 1;
    for(ll i = 0; i < h; ++i) {
        v.push_back({prev, cur});
        prev = cur;
        cur++;
    }

    prev = 1;
    for(ll i = 0; i < d - h; ++i) {
        v.push_back({prev, cur});
        prev = cur;
        cur++;
    }

    while(cur <= n) {
        if(d > h) v.push_back({1, cur});
        else v.push_back({2, cur});
        cur++;
    }

    for(auto i : v) cout << i.first << ' ' << i.second << '\n';
    return 0;
}